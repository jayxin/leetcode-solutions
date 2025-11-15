SCRIPT_DIR := $(shell git rev-parse --show-toplevel)/scripts
PROGRAM_LANG := c

.PHONY : build
build:
	@bash $(SCRIPT_DIR)/$(PROGRAM_LANG)/build.sh

.PHONY : run
run:
	@bash $(SCRIPT_DIR)/$(PROGRAM_LANG)/run.sh

.PHONY : check
check:
	@bash $(SCRIPT_DIR)/check.sh

.PHONY : clean
clean:
	@bash $(SCRIPT_DIR)/clean.sh
