#!/bin/bash

# Color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

run_test() {
    local description="$1"
    shift
    local expected_exit_code="$1"
    shift
    local args=("$@")

    echo -e "${BLUE}Testing $description...${NC}"
    ./push_swap "${args[@]}"
    local actual_exit_code=$?

    if [ $actual_exit_code -eq $expected_exit_code ]; then
        echo -e "${GREEN}Test passed: $description${NC}"
    else
        echo -e "${RED}Test failed: $description (Expected exit code: $expected_exit_code, Actual exit code: $actual_exit_code)${NC}"
    fi
}

# Test cases
run_test "with no arguments" 1
run_test "with non-digit arguments" 1 abc def
run_test "with duplicate arguments" 1 123 456 123
run_test "with multiple signs" 1 -+123 456
run_test "with valid arguments" 0 123 456 789
run_test "with overflow/underflow values" 1 2147483648 -2147483649

# Varied length tests with randomized variables
echo -e "${YELLOW}Varied length tests with randomized variables:${NC}"

# Test with a random number of arguments between 1 and 10
random_args_count=$((RANDOM % 10 + 1))
random_args=()
while [ ${#random_args[@]} -lt $random_args_count ]; do
    random_num=$((RANDOM % 1000 + 1))
    if [[ ! " ${random_args[@]} " =~ " $random_num " ]]; then
        random_args+=($random_num)
    fi
done
run_test "with $random_args_count random arguments (no duplicates)" 0 "${random_args[@]}"

# Test with a random number of arguments between 50 and 100
random_args_count=$((RANDOM % 51 + 50))
random_args=()
while [ ${#random_args[@]} -lt $random_args_count ]; do
    random_num=$((RANDOM % 1000 + 1))
    if [[ ! " ${random_args[@]} " =~ " $random_num " ]]; then
        random_args+=($random_num)
    fi
done
run_test "with $random_args_count random arguments (no duplicates)" 0 "${random_args[@]}"

# Test with a random number of arguments between 500 and 1000
random_args_count=$((RANDOM % 501 + 500))
random_args=()
while [ ${#random_args[@]} -lt $random_args_count ]; do
    random_num=$((RANDOM % 1000 + 1))
    if [[ ! " ${random_args[@]} " =~ " $random_num " ]]; then
        random_args+=($random_num)
    fi
done
run_test "with $random_args_count random arguments (no duplicates)" 0 "${random_args[@]}"

# Mixed character tests
run_test "with mixed characters and digits" 1 abc123 def456
run_test "with mixed characters, digits, and signs" 1 -abc+123 def-456
run_test "with mixed valid and invalid arguments" 1 123 abc 456 def