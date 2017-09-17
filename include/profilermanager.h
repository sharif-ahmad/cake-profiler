/*
 * =====================================================================================
 *
 *       Filename:  profilermanager.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/16/2017 01:28:17 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __PROFILERMANAGER_H__
#define __PROFILERMANAGER_H__

#include <chrono>
#include <map>
#include <memory>
#include <limits>

namespace poc
{

class Logger;

class ProfilerManager final
{
    struct ExecutionDurationTracker
    {
        std::chrono::high_resolution_clock::duration
            min{std::chrono::high_resolution_clock::duration::max()}
            , max{std::chrono::high_resolution_clock::duration::min()}
            , sum{std::chrono::high_resolution_clock::duration::zero()};
        size_t count;
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
    void addExecutionDuration(const std::string& name, std::chrono::high_resolution_clock::duration duration);

    void generateReport() const;
};

}

#endif // __PROFILERMANAGER_H__

