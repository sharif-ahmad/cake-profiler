
#include <profilercontainer.h>

namespace poc
{

ProfilerContainer& ProfilerContainer::getInstance()
{
    thread_local ProfilerContainer profilerContainer;
    return profilerContainer;
}

void ProfilerContainer::addProfiler(std::shared_ptr<Profiler> profiler)
{
    container.push_back(profiler);
}

void ProfilerContainer::removeProfiler()
{
    container.pop_back();
}

}
