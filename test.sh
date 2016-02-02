#!/usr/bin/env bash

_clean() {
    rm -rf build
}

_make() {
    mkdir build
    pushd build
    cmake -Dtesting_macro=ON ..
    make
    popd
}

_clean
_make
build/runTests
