# Sets the minimum version of CMake required to build your native library.
# This ensures that a certain set of CMake features is available to
# your build.

cmake_minimum_required(VERSION 3.4.1)

# Specifies a library name, specifies whether the library is STATIC or
# SHARED, and provides relative paths to the source code. You can
# define multiple libraries by adding multiple add_library() commands,
# and CMake builds them for you. When you build your app, Gradle
# automatically packages shared libraries with your APK.

add_library( native-lib
             SHARED
             src/main/cpp/native-lib.cpp )

# Store the directory where oboe is
set (OBOE_DIR /home/thomas/git/Tuner/oboe)

# Add the library as a subdirectory
add_subdirectory (${OBOE_DIR} ./oboe)

# Specify the path to the oboe header files
include_directories (${OBOE_DIR}/include)

#Specify the libraries wich our native library is dependent on
target_link_libraries(native-lib log oboe)

