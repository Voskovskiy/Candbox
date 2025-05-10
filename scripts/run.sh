#!/bin/bash

# Determine absolute path to this script's directory
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SRC_DIR="$SCRIPT_DIR/../src"
BUILD_DIR="$SCRIPT_DIR/../.build"

# Check if filename is provided
if [ -z "$1" ]; then
    echo "Usage: $0 <filename.c>"
    exit 1
fi

filename="$1"
source_path="$SRC_DIR/$filename"
binary_name="${filename%.c}"
output_path="$BUILD_DIR/$binary_name"

# Check if the source file exists
if [ ! -f "$source_path" ]; then
    echo "❌ File not found: $source_path"
    exit 1
fi

# Ensure build directory exists
mkdir -p "$BUILD_DIR"

# Compile
echo "Compiling $source_path..."
gcc "$source_path" -o "$output_path"

if [ $? -eq 0 ]; then
    echo "✅ Compilation succeeded. Running $binary_name..."
    echo "--------------------------"
    "$output_path"
else
    echo "❌ Compilation failed."
fi
