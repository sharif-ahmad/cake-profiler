#ifndef __PROFILERMANAGER_H__
#define __PROFILERMANAGER_H__

#include <map>
#include <memory>
#include <mutex>
#include <limits>
#include <pocdef.h>

namespace poc
{

class ILogger;

class ProfilerManager final
{
    struct DurationTracker
    {
        duration min{duration::max()}, max{duration::min()}, sum{duration::zero()};
        size_t count{0};

        void update(const duration& duration);
    };

    struct CallFrequencyTracker
    {
        DurationTracker durationTracker;
        clock::time_point prevCallTime{};
    };

    mutable std::mutex durationTrackerMutex;
    std::map<std::string, DurationTracker> execDurationTrackerMap;
    std::map<std::string, CallFrequencyTracker> callFrequencyTrackerMap;
    std::shared_ptr<ILogger> pLogger;

    ProfilerManager() = delete;
    ProfilerManager(const ProfilerManager&) = delete;

    ProfilerManager& operator=(const ProfilerManager&) = delete;

    explicit ProfilerManager(std::shared_ptr<ILogger> pLogger);

public:

    ~ProfilerManager();

    static ProfilerManager& getInstance();

    void setLogger(std::shared_ptr<ILogger> logger);
    void addExecutionDuration(const std::string& name, duration duration);

    void addCallTime(const std::string& name, const clock::time_point& time);

    void generateReport() const;
};

}

#endif // __PROFILERMANAGER_H__

