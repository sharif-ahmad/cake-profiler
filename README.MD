# Piece of cake profiler

__Piece of cake profiler__ (aka. __poc profiler__) is a simple performance profiler for
c++. It tracks functions execution and generates reports with min, max and average
execution time for a function. It is very simple and easy to use.

##### How to Build:
__poc-profiler__ uses CMake as build system. It is easy to generate Makefiles or project files for different compiler and/or IDE.

```
git clone https://github.com/sharif-ahmad/poc-profiler.git poc-profiler
cd poc-profiler
mkdir build && cd build
cmake ..
cmake --build .
```
*For android build:*

```
git clone https://github.com/sharif-ahmad/poc-profiler.git poc-profiler
cd poc-profiler
mkdir build && cd build
cmake .. \
  -DCMAKE_SYSTEM_NAME=Android \
  -DCMAKE_SYSTEM_VERSION=21 \
  -DCMAKE_ANDROID_ARCH_ABI=armeabi-v7a \
  -DCMAKE_ANDROID_NDK=/path/to/android-ndk \
  -DCMAKE_ANDROID_STL_TYPE=gnustl_static

cmake --build .
```

##### Doc:

* `PROFILE_INIT(logger)` : (optional) Initializes profiler with custom logger instance. Your logger class must be derived from `poc::Logger`. Default logger prints output to `stdout`.
* `PROFILE_BLOCK(name)` : Profiles a block (surrounded by curly braces) of code. `name` must be unique for each block you want to profile.
* `PROFILE_BLOCK_START(name)` : This macro along with `PROFILE_BLOCK_END` profiles surrounded statemet(s).
* `PROFILE_BLOCK_END` : see `PROFILE_BLOCK_START`
* `PROFILE_FUNCTION`  : Profiles an entire function. Caution: this macro uses `__FUNCTION__` which does not give full qualified function name. To avoid name conflicts use `PROFILE_BLOCK` with unique name.
* `PROFILE_GENERATE_REPORT` : (optional) Generates and prints reports. Calling this macro is not optional. Report will be automatically generated when program exits.
