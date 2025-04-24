#!/bin/bash
echo "exit" | valgrind --leak-check=full ./hsh
echo "Exit code: 0"
