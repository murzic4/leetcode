SHELL := /bin/bash

.PHONY: test clean

test:
	@passed=0; failed=0; results=""; \
	for d in [0-9][0-9][0-9][0-9]_* parallel/*/ top_interview/*/; do \
		dir=$${d%/}; \
		echo "=== $$dir ==="; \
		if make --no-print-directory -C "$$dir" test; then \
			results="$$results$${dir##*/}=solved"$$'\n'; \
			passed=$$((passed+1)); \
		else \
			results="$$results$${dir##*/}=stub"$$'\n'; \
			failed=$$((failed+1)); \
		fi; \
	done; \
	printf '%s' "$$results" | tools/update_readme.sh README.md; \
	echo ""; \
	echo "Summary: $$passed passed, $$failed failed"

clean:
	@for d in [0-9][0-9][0-9][0-9]_*; do make --no-print-directory -C "$$d" clean; done; \
	for d in parallel/*/; do make --no-print-directory -C "$$d" clean; done; \
	for d in top_interview/*/; do make --no-print-directory -C "$$d" clean; done
