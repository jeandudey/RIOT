MODULE = cc26xx_cc13xx

DIRS += periph
ifneq (,$(filter cc26xx_cc13xx_rf,$(USEMODULE)))
  DIRS += coresdk
  DIRS += radio
endif

# (file triggers compiler bug. see #5775)
SRC_NOLTO += vectors.c

include $(RIOTBASE)/Makefile.base
