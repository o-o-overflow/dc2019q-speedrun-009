#!/bin/sh -e

RESULT=$(echo "1adam" | nc -q 1 "$1" "$2")
echo "$RESULT" | grep "<insert something clever>"
echo "$RESULT" | grep "Choose wisely."
echo "$RESULT" | grep "1, 2, or 3"
echo "$RESULT" | grep "<ending message>"

RESULT=$(echo "2%n%n%n" | nc -q 1 "$1" "$2")
echo "$RESULT" | grep "nope"

RESULT=$(echo "2hello" | nc -q 1 "$1" "$2")
echo "$RESULT" | grep "Is that it"
echo "$RESULT" | grep "hello"
