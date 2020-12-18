
cmake_minimum_required(VERSION 3.10)
project(nuburn VERSION 1.0)
configure_file(config.h.in config.h @ONLY)

add_compile_options(-Wall -Wextra -pedantic) 
add_executable(nuburn 
    ../src/main.c
    ../src/NucLibUsb.c
    ../src/UXmodem.c
    ../src/crc32.c
    ../src/device.c
    ../src/minIni.c
    ../src/parse.c
    ../src/read_file.c
    ../src/result.c)
target_include_directories(nuburn PRIVATE "${PROJECT_BINARY_DIR}")

find_path(LIBUSB_INCLUDE_DIR
  NAMES libusb.h
  PATH_SUFFIXES "include" "libusb" "libusb-1.0")
find_library(LIBUSB_LIBRARY
  NAMES usb-1.0
  PATH_SUFFIXES "lib" "lib32" "lib64")

target_link_libraries(nuburn PRIVATE "${LIBUSB_LIBRARY}")
target_include_directories(nuburn PRIVATE "${LIBUSB_INCLUDE_DIR}")

install(TARGETS nuburn DESTINATION bin)
install(DIRECTORY "${nuburn_SOURCE_DIR}/src/nudata" DESTINATION data)
