#!/bin/bash
# helpful command: git submodule update --init
# helpful command: git submodule update --init --recursive
rm -rf build
mkdir build
cd build
 cmake  \
         -DPYTHON_EXECUTABLE=/Users/isaacmeyer/miniconda3/bin/python \
         -DPYTHON_INCLUDE_DIR=$(python -c "import sysconfig; print(sysconfig.get_path('include'))")  \
         -DPYTHON_LIBRARY=$(python -c "import sysconfig; print(sysconfig.get_config_var('LIBDIR'))") \
         ../
