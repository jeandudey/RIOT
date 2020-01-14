MODULE = cc26xx_cc13xx_coresdk

# e.g.: cc13x2
SDK_LIB_NAME = $(CPU)

SDK_NORTOS = $(CURDIR)/vendor/coresdk_cc13xx_cc26xx/kernel/nortos
SDK_DRIVERS = $(CURDIR)/vendor/coresdk_cc13xx_cc26xx/source/ti/drivers

SDK_DEVICES =
ifeq ($(CPU),cc13x2)
SDK_DEVICES = $(CURDIR)/vendor/coresdk_cc13xx_cc26xx/source/ti/devices/cc13x2_cc26x2
else ifeq ($(CPU),cc26x2)
SDK_DEVICES = $(CURDIR)/vendor/coresdk_cc13xx_cc26xx/source/ti/devices/cc13x2_cc26x2
else ifeq ($(CPU),cc13x0)
SDK_DEVICES = $(CURDIR)/vendor/coresdk_cc13xx_cc26xx/source/ti/devices/cc13x0
else ifeq ($(CPU),cc26x0)
SDK_DEVICES = $(CURDIR)/vendor/coresdk_cc13xx_cc26xx/source/ti/devices/cc26x0
endif

SDK_LIBFILES += $(SDK_NORTOS)/lib/nortos_$(SDK_LIB_NAME).am4fg
SDK_LIBFILES += $(SDK_DRIVERS)/rf/lib/rf_multiMode_$(SDK_LIB_NAME).am4fg
SDK_LIBFILES += $(SDK_DRIVERS)/lib/drivers_$(SDK_LIB_NAME).am4fg
SDK_LIBFILES += $(SDK_DEVICES)/driverlib/bin/gcc/driverlib.lib

OBJ += $(SDK_LIBFILES)

ifeq (, $(__RIOTBUILD_FLAG))
  $(error You cannot build a module on its own. Use "make" in your application's directory instead.)
endif

.PHONY: all clean

all:
	$(Q)$(RM) $(BINDIR)/$(MODULE).a
	$(Q)$(AR) $(ARFLAGS) $(BINDIR)/$(MODULE).a $(SDK_LIBFILES)
