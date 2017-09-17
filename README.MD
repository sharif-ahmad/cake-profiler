# Piece of cake profiler

__Piece of cake profiler__ (aka. __poc profiler__) is a simple performance profiler for
c++. It tracks functions execution and generates reports with min, max and average
execution time for a function. It is very simple and easy to use.

__Doc:__

`PROFILE_INIT(logger)`      : (optional) Initializes profiler with custom logger instance. Your logger class must be derived from `poc::Logger`. Default logger prints output to `stdout`.

`PROFILE_BLOCK(name)`       : Profiles a block (surrounded by curly braces) of code. `name` must be unique for each block you want to profile.

`PROFILE_BLOCK_START(name)` : This macro along with `PROFILE_BLOCK_END` profiles surrounded statemet(s).

`PROFILE_BLOCK_END`         : see `PROFILE_BLOCK_START`

`PROFILE_FUNCTION`          : Profiles an entire function. Caution: this macro uses `__FUNCTION__` which does not give full qualified function name. To avoid name conflicts use `PROFILE_BLOCK` with unique name.

`PROFILE_GENERATE_REPORT`   : (optional) Generates and prints reports. Calling this macro is not optional. Report will be automatically generated when program exits.
