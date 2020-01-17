ifeq (, $(__RIOTBUILD_FLAG))
  $(error You cannot build a module on its own. Use "make" in your application's directory instead.)
endif

#
# enable second expansion of prerequisites.
#
# Doing that here enables it globally for all modules and the application.
#
# See https://www.gnu.org/software/make/manual/html_node/Secondary-Expansion.html
# for what it can be used for.
.SECONDEXPANSION:

unexport DIRS
DIRS := $(sort $(abspath $(DIRS)))

MODULE ?= $(shell basename $(CURDIR))

.PHONY: all clean $(DIRS:%=ALL--%) $(DIRS:%=CLEAN--%)

all: $(BINDIR)/$(MODULE).a ..nothing

..nothing:
	@:

clean:: $(DIRS:%=CLEAN--%)

$(DIRS:%=ALL--%):
	$(QQ)"$(MAKE)" -C $(@:ALL--%=%)

$(DIRS:%=CLEAN--%):
	$(QQ)"$(MAKE)" -C $(@:CLEAN--%=%) clean

## submodules
ifeq (1, $(SUBMODULES))
  # don't use *.c as SRC if SRC is empty (e.g., no module selected)
  NO_AUTO_SRC := 1

  # allow different submodule basename (e.g., MODULE=cpu_periph_common, but match just periph_%)
  BASE_MODULE ?= $(MODULE)

  # for each $(BASE_MODULE)_<name> in USEMODULE, add <name>.c to SRC
  SRC += $(patsubst $(BASE_MODULE)_%,%.c,$(filter $(BASE_MODULE)_%,$(USEMODULE)))

  # don't fail if a selected *.c file does not exist
  ifeq (1, $(SUBMODULES_NOFORCE))
    SRC := $(filter $(SRC), $(wildcard *.c))
  endif
endif


$(BINDIR)/$(MODULE)/:
	$(Q)mkdir -p $@

$(BINDIR)/$(MODULE).a: $(BINDIR)/$(MODULE)/

# Build the archive from the output directory to create relative thin archives
# This allows having them valid in and outside of docker
$(BINDIR)/$(MODULE).a: $(DIRS:%=ALL--%)
	@# Recreate archive to cleanup deleted/non selected source files objects
	$(Q)$(RM) $@
	$(Q)cp $(PREBUILT_LIB) $(BINDIR)/$(MODULE).a

CXXFLAGS = $(filter-out $(CXXUWFLAGS), $(CFLAGS)) $(CXXEXFLAGS)
CCASFLAGS = $(filter-out $(CCASUWFLAGS), $(CFLAGS)) $(CCASEXFLAGS)

# pull in dependency info for *existing* .o files
# deleted header files will be silently ignored
-include $(DEP)
