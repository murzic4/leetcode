SHELL := /bin/bash

.PHONY: test clean

test:
	@passed=0; failed=0; \
	for d in */; do \
		d=$${d%/}; \
		echo "=== $$d ==="; \
		if make --no-print-directory -C "$$d" test; then \
			passed=$$((passed+1)); \
		else \
			failed=$$((failed+1)); \
		fi; \
	done; \
	echo ""; \
	echo "Summary: $$passed passed, $$failed failed"

clean:
	@for d in */; do make --no-print-directory -C "$$d" clean; done
