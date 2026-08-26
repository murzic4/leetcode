SHELL := /bin/bash

.PHONY: test clean

test:
	@passed=0; failed=0; \
	for d in [0-9][0-9][0-9][0-9]_*; do \
		echo "=== $$d ==="; \
		if make --no-print-directory -C "$$d" test; then \
			sed -i -E "/$$d/ s/\| [^|]* \|$$/| solved |/" README.md; \
			passed=$$((passed+1)); \
		else \
			sed -i -E "/$$d/ s/\| [^|]* \|$$/| stub |/" README.md; \
			failed=$$((failed+1)); \
		fi; \
	done; \
	echo ""; \
	echo "Summary: $$passed passed, $$failed failed"

clean:
	@for d in [0-9][0-9][0-9][0-9]_*; do make --no-print-directory -C "$$d" clean; done
