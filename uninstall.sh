#!/bin/bash

if [ "$EUID" -ne 0 ]; then
  echo "Please run as root (using sudo)."
  exit
fi

PREFIX="/usr"
LIB_PATH="$PREFIX/lib/libfreelibc.a"
INCLUDE_PATH="$PREFIX/include/freelibc"
CONF_PATH="/etc/ld.so.conf.d/freelibc.conf"

if [ -f "$LIB_PATH" ]; then
  echo "Removing library: $LIB_PATH"
  rm "$LIB_PATH"
else
  echo "Library not found: $LIB_PATH"
fi

if [ -d "$INCLUDE_PATH" ]; then
  echo "Removing include directory: $INCLUDE_PATH"
  rm -r "$INCLUDE_PATH"
else
  echo "Include directory not found: $INCLUDE_PATH"
fi

if [ -f "$CONF_PATH" ]; then
  echo "Removing ldconfig configuration: $CONF_PATH"
  rm "$CONF_PATH"
else
  echo "ldconfig configuration not found: $CONF_PATH"
fi

echo "Updating linker cache..."
ldconfig

echo "freelibc has been uninstalled from $PREFIX"
