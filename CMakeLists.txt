﻿# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)
add_compile_options("/std:c++17")

project ("PBDesign1")

# Include sub-projects.
add_subdirectory ("PBDesign1")
add_subdirectory ("fmt")

