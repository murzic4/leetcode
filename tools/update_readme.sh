#!/usr/bin/env bash
# Rewrite the status (and problem-name) cells of the README tables.
#
# Input on stdin: one `folder=solved` or `folder=stub` line per problem folder.
# A solved problem gets its name and status wrapped as markdown links
# (`[Two Sum](#)` / `[solved](#)`, which render in the link colour); anything
# else gets a plain name and `stub`.
set -euo pipefail

readme="${1:-README.md}"

declare -A status=()
while IFS='=' read -r key value || [ -n "${key:-}" ]; do
    [ -n "$key" ] || continue
    status["$key"]="$value"
done

program='BEGIN{'
for key in "${!status[@]}"; do
    program+="st[\"$key\"]=\"${status[$key]}\";"
done
program+=$'}\n'

program+=$(cat <<'AWK'
function trim(s) { sub(/^[[:space:]]+/, "", s); sub(/[[:space:]]+$/, "", s); return s }

function setcell(cell, value,   lead, trail) {
    lead = cell
    sub(/[^[:space:]].*$/, "", lead)
    trail = cell
    sub(/^.*[^[:space:]]/, "", trail)
    return lead value trail
}

BEGIN {
    FS = "|"
    n = 0
    for (k in st) keys[++n] = k
    # longest key first, so no folder name can shadow a longer one
    for (i = 2; i <= n; i++) {
        v = keys[i]
        for (j = i - 1; j >= 1 && length(keys[j]) < length(v); j--) keys[j + 1] = keys[j]
        keys[j + 1] = v
    }
    namecol = 0
}

/^\|/ {
    if (namecol != 0 && $0 !~ /^\|[[:space:]]*-/ && trim($(NF - 1)) != "Status") {
        key = ""
        for (i = 1; i <= n; i++) if (index($0, keys[i]) > 0) { key = keys[i]; break }
        if (key != "") {
            solved = (st[key] == "solved")
            name = trim($(namecol))
            sub(/^\[/, "", name)
            sub(/\]\(#\)$/, "", name)
            $(namecol) = setcell($(namecol), solved ? "[" name "](#)" : name)
            $(NF - 1) = setcell($(NF - 1), solved ? "[solved](#)" : "`stub`")
            line = ""
            for (i = 2; i <= NF; i++) line = line "|" $i
            print line
            next
        }
    }
    if (trim($(NF - 1)) == "Status") {
        namecol = 0
        for (i = 2; i < NF; i++) if (trim($i) == "Problem" || trim($i) == "Task") namecol = i
    }
    print
    next
}

{ print }
AWK
)

tmp="./tmp/readme.$$.md"
mkdir -p ./tmp
trap 'rm -f "$tmp"' EXIT

awk "$program" "$readme" > "$tmp"
mv "$tmp" "$readme"
