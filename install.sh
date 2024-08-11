#!/bin/bash

if [ "$EUID" -ne 0 ]; then
  echo "Please run as root (using sudo)."
  exit
fi

PREFIX="/usr"
LIB_PATH="$PREFIX/lib/libfreelibc.a"
INCLUDE_PATH="$PREFIX/include/freelibc"

if [ -f "$LIB_PATH" ] || [ -d "$INCLUDE_PATH" ]; then
  echo "Warning: freelibc appears to be already installed."
  echo -n "Do you want to overwrite existing files? (Y/n): "
  read -n 1 choice
  echo
  choice=${choice:-y}
  case "$choice" in 
    y|Y ) echo "Overwriting existing files...";;
    * ) echo "Installation aborted."; exit;;
  esac
fi

cmake -B build -DCMAKE_INSTALL_PREFIX="$PREFIX"
cmake --build build
cmake --install build

echo "Updating linker cache..."
echo "/usr/lib" > /etc/ld.so.conf.d/freelibc.conf
ldconfig

echo "freelibc has been installed to $PREFIX"
echo "Library installed in: $PREFIX/lib"
echo "Headers installed in: $PREFIX/include/freelibc"
