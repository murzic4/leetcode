#!/usr/bin/env bash
# Rewrite the status, problem-name, `Folder` and `Where` cells of the README tables.
#
# Input on stdin: one `folder=status` or `folder=status|relative/path` line per
# problem folder. A solved problem gets its name linked to the problem folder and
# its status as `[solved](#)`; anything else gets a plain name and `stub`.
# The `Folder`/`Where` columns are always kept as plain text (no links, no code
# spans), so they render in the default colour.
set -euo pipefail

readme="${1:-README.md}"

declare -A status=()
declare -A path=()
while IFS='=' read -r key rest || [ -n "${key:-}" ]; do
    [ -n "$key" ] || continue
    status["$key"]="${rest%%|*}"
    if [[ "$rest" == *"|"* ]]; then
        path["$key"]="${rest#*|}"
    else
        path["$key"]="$key"
    fi
done

program='BEGIN{'
for key in "${!status[@]}"; do
    program+="st[\"$key\"]=\"${status[$key]}\";pt[\"$key\"]=\"${path[$key]}\";"
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

# strip a markdown link or an inline code span, keeping only the visible text
function undecorate(s) {
    if (s ~ /^\[[^]]*\][[:space:]]*\([^)]*\)$/) {
        sub(/^\[/, "", s)
        sub(/\][[:space:]]*\([^)]*\)$/, "", s)
        return s
    }
    if (s ~ /^`.*`$/) {
        sub(/^`+/, "", s)
        sub(/`+$/, "", s)
        return s
    }
    return s
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
    nplain = 0
}

/^\|/ {
    if (trim($(NF - 1)) == "Status") {
        namecol = 0
        nplain = 0
        for (i = 2; i < NF; i++) {
            t = trim($i)
            if (t == "Problem" || t == "Task") namecol = i
            if (t == "Folder" || t == "Where") plain[++nplain] = i
        }
        print
        next
    }
    if ($0 ~ /^\|[[:space:]]*-/ || namecol == 0) {
        print
        next
    }

    key = ""
    for (i = 1; i <= n; i++) if (index($0, keys[i]) > 0) { key = keys[i]; break }
    if (key != "") {
        solved = (st[key] == "solved")
        name = undecorate(trim($(namecol)))
        $(namecol) = setcell($(namecol), solved ? "[" name "](" pt[key] "/)" : name)
        $(NF - 1) = setcell($(NF - 1), solved ? "[solved](#)" : "`stub`")
        for (i = 1; i <= nplain; i++) {
            c = plain[i]
            $(c) = setcell($(c), undecorate(trim($(c))))
        }
        line = ""
        for (i = 2; i <= NF; i++) line = line "|" $i
        print line
        next
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
