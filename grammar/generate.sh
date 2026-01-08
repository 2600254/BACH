#!/bin/bash
# Generate ANTLR4 parser from Cypher.g4 grammar

# ANTLR4 jar path - adjust if needed
ANTLR4_JAR="/usr/share/java/antlr4-runtime-4.13.1.jar"

# Check if ANTLR4 is available
if ! command -v antlr4 &> /dev/null; then
    echo "ANTLR4 not found in PATH. Please install ANTLR4:"
    echo "  sudo apt-get install antlr4"
    echo "  or download from https://www.antlr.org/"
    exit 1
fi

# Directories
GRAMMAR_DIR="$(dirname "$0")"
GENERATED_DIR="/home/drbee/BACH/parser/generated"

# Create generated directory if it doesn't exist
mkdir -p "$GENERATED_DIR"

# Generate parser
echo "Generating ANTLR4 parser for Cypher.g4..."
antlr4 \
    -Dlanguage=Cpp \
    -no-listener \
    -visitor \
    -o "$GENERATED_DIR" \
    -package parser \
    "$GRAMMAR_DIR/Cypher.g4"

echo "Done! Generated files are in: $GENERATED_DIR"
echo ""
echo "Generated files:"
ls -la "$GENERATED_DIR"/*.h "$GENERATED_DIR"/*.cpp 2>/dev/null || echo "No files found"
