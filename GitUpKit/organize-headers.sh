#!/bin/bash

rm -r Headers/GitUpKit
mkdir -p Headers/GitUpKit

for header in */*.h GitUpKit.h; do
    header_name=${header##*Core/}
    header_name=${header_name##*Extensions/}
    header_name=${header_name##*Components/}
    header_name=${header_name##*Interface/}
    header_name=${header_name##*Logging/}
    header_name=${header_name##*Utilities/}
    header_name=${header_name##*Views/}
    echo "Header name: ${header_name}"
    echo "Header: ${header}"
    ln -s "${PWD}/${header}" "${PWD}/Headers/GitUpKit/${header_name}" 
done