#ifndef __CAKEDEF_H__
#define __CAKEDEF_H__

#include <chrono>

namespace cake
{

using clock = std::chrono::high_resolution_clock;
using time_point = clock::time_point;
using duration = clock::duration;

using time_unit = std::chrono::milliseconds;

}

#endif // __CAKEDEF_H__
