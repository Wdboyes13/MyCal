#!/usr/bin/env bash

set -ex

cd ..
find . -name '*~' -delete
find . -name 'app' -delete
find . -name '*#' -delete
rm -rf build

