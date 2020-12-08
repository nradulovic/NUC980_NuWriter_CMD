

AUTOMAKE_OPTIONS=foreign
bin_PROGRAMS=nuburner
nuburner_SOURCES= main.c read_file.c device.c NucLibUsb.c parse.c UXmodem.c crc32.c minIni.c
EXTRA_DIST = nudata README

# Since we can override --prefix at install time we need to define this macro at Make level
# not at configure level
AM_CPPFLAGS = -DNUDATA_PATH='"$(prefix)/share/nudata"'

nudata_dir = $(prefix)/share/nudata/
nudata__DATA =	nudata/xusb64.bin \
		nudata/xusb128.bin \
		nudata/xusb.bin \
		nudata/xusb16.bin

syscfg_dir = $(prefix)/share/nudata/sys_cfg
syscfg__DATA =  nudata/sys_cfg/NUC980DF61YC.ini \
		nudata/sys_cfg/NUC980DK61Y.ini \
		nudata/sys_cfg/NUC980DK61YC.ini \
		nudata/sys_cfg/NUC980DR61Y.ini 

LIBS =$(LIBUSB_CFLAGS)  $(LIBUSB_LIBS) -lpthread
CFLAGS = $(LIBUSB_CFLAGS)

