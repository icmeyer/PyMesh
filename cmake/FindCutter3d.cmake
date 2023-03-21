# Find cutter3d
# https://github.com/loopstring/3d-cutter
# The following variables are set.
#
# CUTTER3D_FOUND
# CUTTER3D_INCLUDE_DIRS
# CUTTER3D_LIBRARIES

# Find include directory.
find_path (CUTTER3D_INCLUDE_DIRS Cutting.h
    PATHS
    $ENV{CUTTER3D_PATH}
    $ENV{CUTTER3D_PATH}/include
    ${PROJECT_SOURCE_DIR}/python/pymesh/third_party/include/
    NO_DEFAULT_PATH)

FIND_LIBRARY(CUTTER3D_LIBRARIES NAMES libcutter3d.a cutter3d
    PATHS
    $ENV{CUTTER3D_PATH}
    $ENV{CUTTER3D_PATH}/lib
    ${PROJECT_SOURCE_DIR}/python/pymesh/third_party/lib/
    NO_DEFAULT_PATH)

# Standard package handling
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Cutter3d
  "Cutter3d could not be found."
  CUTTER3D_LIBRARIES CUTTER3D_INCLUDE_DIRS)

mark_as_advanced(
  CUTTER3D_INCLUDE_DIRS
  CUTTER3D_LIBRARIES
)

