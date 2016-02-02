#!/usr/bin/env bash

_clean() {
    rm -rf build
    rm -rf lib
    rm -rf tests/lib
}

_get_libraries() {
    echo "getting Particle firmware"
    svn --quiet export https://github.com/spark/firmware/tags/v0.4.9 lib/firmware
    echo "getting GoogleTest"
    svn --quiet export https://github.com/google/googletest/tags/release-1.7.0 lib/gtest
    echo "getting GoogleMock"
    svn --quiet export https://github.com/google/googlemock/tags/release-1.7.0 lib/gmock
}

_clean
_get_libraries
