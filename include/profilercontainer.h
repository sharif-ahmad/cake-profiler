#ifndef __PROFILERCONTAINER_H__
#define __PROFILERCONTAINER_H__

#include <profiler.h>
#include <vector>
#include <memory>


namespace poc
{

class ProfilerContainer final
{
    std::vector<std::shared_ptr<Profiler>> container;

    ProfilerContainer(const ProfilerContainer&) = delete;

    ProfilerContainer& operator=(const ProfilerContainer&) = delete;

    explicit ProfilerContainer() = default;

public:

    ~ProfilerContainer() = default;

    static ProfilerContainer& getInstance();

    void addProfiler(std::shared_ptr<Profiler> profiler);

    void removeProfiler();
};

}

#endif // __PROFILERCONTAINER_H__

