#!/bin/bash

# Color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NC='\033[0m' # No Color

# Checker binary
CHECKER="./checker_OS"

# Function to run a test case with valgrind
run_test() {
    local test_name="$1"
    local command="$2"
    local expected_exit_code="$3"
    echo "Testing: $command"
    valgrind --leak-check=full --error-exitcode=1 $command &> /dev/null
    local exit_code=$?
    if [ $exit_code -eq $expected_exit_code ]; then
        echo -e "${GREEN}$test_name passed.${NC}"
    else
        echo -e "${RED}$test_name failed.${NC}"
    fi
}
# Error management tests
echo "Testing error management..."

# Test 1: Non-numeric parameter
run_test "Non-numeric parameter test" "./push_swap non_numeric_param" 1

# Test 2: Duplicate numeric parameter
run_test "Duplicate numeric parameter test" "./push_swap 1 2 3 2" 1

# Test 3: Integer overflow
run_test "Integer overflow test" "./push_swap 2147483648" 1

# Identity tests
echo "Testing identity cases..."

# Test 4: No parameters
run_test "No parameters test" "./push_swap" 0

# Test 5: Single value
run_test "Single value test" "./push_swap 42" 0

# Test 6: Two sorted values
run_test "Two sorted values test" "./push_swap 2 3" 0

# Test 7: Four sorted values
run_test "Four sorted values test" "./push_swap 0 1 2 3" 0

# Test 8: Ten sorted values
run_test "Ten sorted values test" "./push_swap 0 1 2 3 4 5 6 7 8 9" 0

# Simple version tests
echo "Testing simple version..."

# Test 9: Simple version test 1
ARG="2 1 0"
echo "Testing: ./push_swap $ARG"
INSTRUCTIONS=$(./push_swap $ARG | wc -l)
./push_swap $ARG | $CHECKER $ARG &> /dev/null
if [ $? -ne 0 ]; then
    echo -e "${RED}Error: Simple version test 1 failed. (Test 9 failed - Incorrect sorting)${NC}"
elif [ "$INSTRUCTIONS" -gt 3 ]; then
    echo -e "${YELLOW}Warning: Simple version test 1 passed but with suboptimal instructions. (Test 9 passed with warning)${NC}"
else
    valgrind --leak-check=full --error-exitcode=1 ./push_swap $ARG &> /dev/null
    if [ $? -eq 0 ]; then
        echo -e "${GREEN}Simple version test 1 passed.${NC}"
    else
        echo -e "${RED}Error: Simple version test 1 failed. (Test 9 failed - Memory leak)${NC}"
    fi
fi

# Test 10: Simple version test 2
NUM_ARGS=$((RANDOM % 4))
ARG=$(shuf -i 0-100 -n $NUM_ARGS | tr '\n' ' ')
echo "Testing: ./push_swap $ARG"
INSTRUCTIONS=$(./push_swap $ARG | wc -l)
./push_swap $ARG | $CHECKER $ARG &> /dev/null
if [ $? -ne 0 ]; then
    echo -e "${RED}Error: Simple version test 2 failed. (Test 10 failed - Incorrect sorting)${NC}"
elif [ "$INSTRUCTIONS" -gt 3 ]; then
    echo -e "${RED}Error: Simple version test 2 failed. (Test 10 failed - Too many instructions)${NC}"
else
    valgrind --leak-check=full --error-exitcode=1 ./push_swap $ARG &> /dev/null
    if [ $? -eq 0 ]; then
        echo -e "${GREEN}Simple version test 2 passed.${NC}"
    else
        echo -e "${RED}Error: Simple version test 2 failed. (Test 10 failed - Memory leak)${NC}"
    fi
fi

# Test 11: Another simple version test 1
ARG="1 5 2 4 3"
echo "Testing: ./push_swap $ARG"
INSTRUCTIONS=$(./push_swap $ARG | wc -l)
./push_swap $ARG | $CHECKER $ARG &> /dev/null
if [ $? -ne 0 ]; then
    echo -e "${RED}Error: Another simple version test 1 failed. (Test 11 failed - Incorrect sorting)${NC}"
elif [ "$INSTRUCTIONS" -gt 12 ]; then
    echo -e "${RED}Error: Another simple version test 1 failed. (Test 11 failed - Too many instructions)${NC}"
elif [ "$INSTRUCTIONS" -eq 8 ]; then
    valgrind --leak-check=full --error-exitcode=1 ./push_swap $ARG &> /dev/null
    if [ $? -eq 0 ]; then
        echo -e "${GREEN}Another simple version test 1 passed with kudos.${NC}"
    else
        echo -e "${RED}Error: Another simple version test 1 failed. (Test 11 failed - Memory leak)${NC}"
    fi
else
    valgrind --leak-check=full --error-exitcode=1 ./push_swap $ARG &> /dev/null
    if [ $? -eq 0 ]; then
        echo -e "${GREEN}Another simple version test 1 passed.${NC}"
    else
        echo -e "${RED}Error: Another simple version test 1 failed. (Test 11 failed - Memory leak)${NC}"
    fi
fi

# Test 12: Another simple version test 2
ARG=$(shuf -i 0-9 -n 5 | tr '\n' ' ')
echo "Testing: ./push_swap $ARG"
INSTRUCTIONS=$(./push_swap $ARG | wc -l)
./push_swap $ARG | $CHECKER $ARG &> /dev/null
if [ $? -ne 0 ]; then
    echo -e "${RED}Error: Another simple version test 2 failed. (Test 12 failed - Incorrect sorting)${NC}"
elif [ "$INSTRUCTIONS" -gt 12 ]; then
    echo -e "${RED}Error: Another simple version test 2 failed. (Test 12 failed - Too many instructions)${NC}"
else
    valgrind --leak-check=full --error-exitcode=1 ./push_swap $ARG &> /dev/null
    if [ $? -eq 0 ]; then
        echo -e "${GREEN}Another simple version test 2 passed.${NC}"
    else
        echo -e "${RED}Error: Another simple version test 2 failed. (Test 12 failed - Memory leak)${NC}"
    fi
fi

# Middle version test
echo "Testing middle version..."
total_score=0
total_moves=0
for i in {1..10}; do
    ARG=$(shuf -i 0-499 -n 100)
    MOVES=$(./push_swap $ARG | wc -l)
    total_moves=$((total_moves + MOVES))
    ./push_swap $ARG | $CHECKER $ARG &> /dev/null
    if [ $? -ne 0 ]; then
        echo -e "${RED}Error: Middle version test failed.${NC}"
        score=0
    elif [ "$MOVES" -lt 700 ]; then
        score=5
    elif [ "$MOVES" -lt 900 ]; then
        score=4
    elif [ "$MOVES" -lt 1100 ]; then
        score=3
    elif [ "$MOVES" -lt 1300 ]; then
        score=2
    elif [ "$MOVES" -lt 1500 ]; then
        score=1
    else
        score=0
    fi
    total_score=$((total_score + score))
done
avg_score=$((total_score / 10))
avg_moves=$((total_moves / 10))
echo -e "${GREEN}Middle version test average score: $avg_score/5${NC}"
echo -e "${GREEN}Middle version test average moves: $avg_moves${NC}"

# Advanced version test
echo "Testing advanced version..."
total_score=0
total_moves=0
for i in {1..10}; do
    ARG=$(shuf -i 0-499 -n 500)
    MOVES=$(./push_swap $ARG | wc -l)
    total_moves=$((total_moves + MOVES))
    ./push_swap $ARG | $CHECKER $ARG &> /dev/null
    if [ $? -ne 0 ]; then
        echo -e "${RED}Error: Advanced version test failed.${NC}"
        score=0
    elif [ "$MOVES" -lt 5500 ]; then
        score=5
    elif [ "$MOVES" -lt 7000 ]; then
        score=4
    elif [ "$MOVES" -lt 8500 ]; then
        score=3
    elif [ "$MOVES" -lt 10000 ]; then
        score=2
    elif [ "$MOVES" -lt 11500 ]; then
        score=1
    else
        score=0
    fi
    total_score=$((total_score + score))
done
avg_score=$((total_score / 10))
avg_moves=$((total_moves / 10))
echo -e "${GREEN}Advanced version test average score: $avg_score/5${NC}"
echo -e "${GREEN}Advanced version test average moves: $avg_moves${NC}"
