#ifndef __CAKE_H__
#define __CAKE_H__

#include <cakedef.h>
#include <profiler.h>
#include <profilermanager.h>
#include <profilercontainer.h>

#ifdef PROFILE_ENABLED
#define PROFILE_INIT(logger) cake::ProfilerManager::getInstance().setLogger(logger);
#define PROFILE_BLOCK(name) cake::Profiler poc_profiler(name, cake::ProfilerManager::getInstance());
#define PROFILE_BLOCK_START(name) cake::ProfilerContainer::getInstance().addProfiler(std::make_shared<cake::Profiler>(name, cake::ProfilerManager::getInstance()));
#define PROFILE_BLOCK_END cake::ProfilerContainer::getInstance().removeProfiler();
#define PROFILE_BLOCK_FREQUENCY(name) cake::ProfilerManager::getInstance().addCallTime(name, cake::clock::now());

#define PROFILE_FUNCTION PROFILE_BLOCK(__FUNCTION__)
#define PROFILE_FUNCTION_FREQUENCY PROFILE_BLOCK_FREQUENCY(__FUNCTION__)
#define PROFILE_GENERATE_REPORT cake::ProfilerManager::getInstance().generateReport();
#else
#define PROFILE_INIT(logger)
#define PROFILE_BLOCK(name)
#define PROFILE_BLOCK_START(name)
#define PROFILE_BLOCK_END
#define PROFILE_BLOCK_FREQUENCY(name)
#define PROFILE_FUNCTION
#define PROFILE_FUNCTION_FREQUENCY
#define PROFILE_GENERATE_REPORT
#endif // ENABLE_PROFILE

#endif // __CAKE_H__

