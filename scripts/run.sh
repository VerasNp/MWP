#!/bin/bash

if [[ $# -ne 1 ]]; then
    echo 'Too many/few arguments, expecting one' >&2
    exit 1
fi

case $1 in
test)
    cmake -B build -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DCMAKE_C_COMPILER=gcc -DCMAKE_BUILD_TYPE=Debug -S . &&
        cmake --build build --config Debug &&
        ctest -VV --test-dir build -R Matrix
    ;;
*)
    echo 'Expected "test"' >&2
    exit 1
    ;;
esac