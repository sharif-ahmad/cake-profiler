#ifndef __POCDEF_H__
#define __POCDEF_H__

#include <chrono>

namespace poc
{

using clock = std::chrono::high_resolution_clock;
using time_point = clock::time_point;
using duration = clock::duration;

using time_unit = std::chrono::milliseconds;

}

#endif // __POCDEF_H__
