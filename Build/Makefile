# GNU Make solution makefile autogenerated by Premake
# Type "make help" for usage help

ifndef config
  config=debug
endif
export config

PROJECTS := string_append_benchmark

.PHONY: all clean help $(PROJECTS)

all: $(PROJECTS)

string_append_benchmark: 
	@echo "==== Building string_append_benchmark ($(config)) ===="
	@${MAKE} --no-print-directory -C . -f string_append_benchmark.make

clean:
	@${MAKE} --no-print-directory -C . -f string_append_benchmark.make clean

help:
	@echo "Usage: make [config=name] [target]"
	@echo ""
	@echo "CONFIGURATIONS:"
	@echo "   debug"
	@echo "   release"
	@echo "   debug32"
	@echo "   release32"
	@echo "   debug64"
	@echo "   release64"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo "   string_append_benchmark"
	@echo ""
	@echo "For more information, see http://industriousone.com/premake/quick-start"
