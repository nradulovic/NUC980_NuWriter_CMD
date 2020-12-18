# NuBurner command tool for NUC980 family processors

The NuBurner Command Tool is a linux console application consisting of
functions to access storage (eg. DRAM, NAND, SPINOR, SPINAND, SD) in NUC980 
family of processors.

## Installation Steps

On Debian or Ubuntu system first install the dependencies:

    sudo apt-get install build_essential cmake libusb-1.0-0-dev

Compilation

    cd NUC980_NuWriter_CMD
    mkdir out
    cd out
    cmake <path_to_source>
    make
    make install

## Examples

    From out directory execute the following script to flash u-boot image to
    nand:

    nuwriter <path_to_source>/scripts/uboot_nand_write.ini




