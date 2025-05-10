#!/bin/bash

# Determine absolute path to this script's directory
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SRC_DIR="$SCRIPT_DIR/../src"
BUILD_DIR="$SCRIPT_DIR/../.build"

# Check for at least one file
if [ $# -lt 1 ]; then
    echo "Usage: $0 <file1.c> [file2.c ...]"
    exit 1
fi

# Gather all full source paths
SOURCE_FILES=()
for file in "$@"; do
    full_path="$SRC_DIR/$file"
    if [ ! -f "$full_path" ]; then
        echo "❌ File not found: $full_path"
        exit 1
    fi
    SOURCE_FILES+=("$full_path")
done

# Determine output binary name from first file (without .c)
BIN_NAME="${1%.c}"
OUTPUT_PATH="$BUILD_DIR/$BIN_NAME"

# Ensure build directory exists
mkdir -p "$BUILD_DIR"

# Compile
echo "🔧 Compiling: ${SOURCE_FILES[*]}"
gcc "${SOURCE_FILES[@]}" -o "$OUTPUT_PATH"

# Run if compile succeeded
if [ $? -eq 0 ]; then
    echo "✅ Build succeeded"
    echo "🚀 Running: $OUTPUT_PATH"
else
    echo "❌ Build failed"
fi