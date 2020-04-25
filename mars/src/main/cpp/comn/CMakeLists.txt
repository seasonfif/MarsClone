# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)
project(comn)
include_directories(.)

file(GLOB comn_srcs "*.cc")

list(APPEND SELF_SRC_FILES ${comn_srcs})

#[[add_library( # Sets the name of the library.
        comn

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        ${comn_srcs})]]
