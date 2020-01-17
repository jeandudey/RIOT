MODULE = cc26xx_cc13xx_coresdk_driverlib

SDK_DEVICES =
ifeq ($(CPU),cc13x2)
SDK_DEVICES = $(CURDIR)/../vendor/coresdk_cc13xx_cc26xx/source/ti/devices/cc13x2_cc26x2
else ifeq ($(CPU),cc26x2)
SDK_DEVICES = $(CURDIR)/../vendor/coresdk_cc13xx_cc26xx/source/ti/devices/cc13x2_cc26x2
else ifeq ($(CPU),cc13x0)
SDK_DEVICES = $(CURDIR)/../vendor/coresdk_cc13xx_cc26xx/source/ti/devices/cc13x0
else ifeq ($(CPU),cc26x0)
SDK_DEVICES = $(CURDIR)/../vendor/coresdk_cc13xx_cc26xx/source/ti/devices/cc26x0
endif

PREBUILT_LIB = $(SDK_DEVICES)/driverlib/bin/gcc/driverlib.lib

include $(RIOTMAKE)/prebuilt.inc.mk
