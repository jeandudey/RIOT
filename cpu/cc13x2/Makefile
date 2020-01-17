# Define the module that is built:
MODULE = cpu

# Add a list of subdirectories, that should also be built:
DIRS += periph $(RIOTCPU)/cortexm_common $(RIOTCPU)/cc26xx_cc13xx

ifneq (,$(filter cc13x2_rf,$(USEMODULE)))
  DIRS += radio
endif

CFLAGS += -DDeviceFamily_CC13X2 -Wno-strict-prototypes

MODEL = $(shell echo $(CPU_MODEL) | tr 'a-z-' 'A-Z_')
CFLAGS += -DDEVICE_$(MODEL)

include $(RIOTBASE)/Makefile.base
