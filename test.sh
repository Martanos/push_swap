#!/bin/bash

# Test cases
echo "Testing with no arguments..."
./push_swap
if [ $? -eq 1 ]; then
    echo "Test passed: Error handled for no arguments"
else
    echo "Test failed: Expected error for no arguments"
fi

echo "Testing with non-digit arguments..."
./push_swap abc def
if [ $? -eq 1 ]; then
    echo "Test passed: Error handled for non-digit arguments"
else
    echo "Test failed: Expected error for non-digit arguments"
fi

echo "Testing with duplicate arguments..."
./push_swap 123 456 123
if [ $? -eq 1 ]; then
    echo "Test passed: Error handled for duplicate arguments"
else
    echo "Test failed: Expected error for duplicate arguments"
fi

echo "Testing with multiple signs..."
./push_swap -+123 456
if [ $? -eq 1 ]; then
    echo "Test passed: Error handled for multiple signs"
else
    echo "Test failed: Expected error for multiple signs"
fi

echo "Testing with valid arguments..."
./push_swap 123 456 789
if [ $? -eq 0 ]; then
    echo "Test passed: Valid arguments accepted"
else
    echo "Test failed: Expected valid arguments to be accepted"
fi

echo "Testing with overflow/underflow values..."
./push_swap 2147483648 -2147483649
if [ $? -eq 1 ]; then
    echo "Test passed: Error handled for overflow/underflow values"
else
    echo "Test failed: Expected error for overflow/underflow values"
fi