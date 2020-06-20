# CMakeList.txt : CMake project for PBDesign1, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

include_directories(".")
include_directories("../fmt/include")

# Add source to this project's executable.
add_executable (PBDesign1 "PBDesign1.cpp" "PBDesign1.h"   "pcl/vectors/fastvec.h" "pcl/policies/allocmodel.h" "pcl/policies/threadmodel.h" "pcl/vectors/dzen.h" "pcl/policies/invalid.h"  "pcl/hashing/autohash.h" "pcl/policies/hashing.h")

# TODO: Add tests and install targets if needed.
target_link_libraries(PBDesign1 PRIVATE fmt::fmt)