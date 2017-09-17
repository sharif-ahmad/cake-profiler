#ifndef __PROFILER_H__
#define __PROFILER_H__
#include <chrono>
#include <string>

namespace poc // piece of cake
{

class ProfilerManager;

class Profiler final
{
    std::chrono::high_resolution_clock::time_point start, end;
    std::string name;

    ProfilerManager& manager;
public:
    Profiler(const std::string& name, ProfilerManager& manager);
    Profiler(std::string&& name, ProfilerManager& manager);

    ~Profiler();
};

}

#endif // __PROFILER_H__

