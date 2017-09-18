#ifndef __PROFILERMANAGER_H__
#define __PROFILERMANAGER_H__

#include <map>
#include <memory>
#include <limits>
#include <pocdef.h>

namespace poc
{

class Logger;

class ProfilerManager final
{
    struct ExecutionDurationTracker
    {
        duration min{duration::max()}, max{duration::min()}, sum{duration::zero()};
        size_t count{0};
    };

    std::map<std::string, ExecutionDurationTracker> durationTrackerMap;
    std::shared_ptr<Logger> pLogger;

    ProfilerManager() = delete;
    ProfilerManager(const ProfilerManager&) = delete;

    ProfilerManager& operator=(const ProfilerManager&) = delete;

    explicit ProfilerManager(std::shared_ptr<Logger> pLogger);

public:

    ~ProfilerManager();

    static ProfilerManager& getInstance();

    void setLogger(std::shared_ptr<Logger> logger);
    void addExecutionDuration(const std::string& name, duration duration);

    void generateReport() const;
};

}

#endif // __PROFILERMANAGER_H__

