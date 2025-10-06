#!/bin/bash
# Quick test script for Linux/Unix

echo "========================================"
echo " Minimal C Compiler - Quick Test"
echo "========================================"
echo ""

# Color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

if [ ! -f "minicompiler" ]; then
    echo -e "${RED}ERROR: minicompiler not found!${NC}"
    echo "Please run 'make' or './build.sh' first."
    exit 1
fi

echo "Creating test file..."
cat > quick_test.c << EOF
int x;
int y;
int result;

x = 10;
y = 20;
result = x + y;
print(result);
EOF

echo ""
echo "Compiling quick_test.c..."
if ./minicompiler quick_test.c quick_test.s; then
    echo ""
    echo -e "${GREEN}SUCCESS! Compilation completed.${NC}"
    echo ""
    echo "Generated MIPS code (first 20 lines):"
    echo "----------------------------------------"
    head -n 20 quick_test.s
    echo "----------------------------------------"
else
    echo ""
    echo -e "${RED}FAILED! Compilation error.${NC}"
fi

echo ""
echo "Cleaning up test files..."
rm -f quick_test.c quick_test.s

echo ""
echo "Test complete!"
