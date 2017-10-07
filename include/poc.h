#ifndef __POC_H__
#define __POC_H__

#include <pocdef.h>
#include <profiler.h>
#include <profilermanager.h>
#include <profilercontainer.h>

#ifdef PROFILE_ENABLED
#define PROFILE_INIT(logger) poc::ProfilerManager::getInstance().setLogger(logger);
#define PROFILE_BLOCK(name) poc::Profiler poc_profiler(name, poc::ProfilerManager::getInstance());
#define PROFILE_BLOCK_START(name) poc::ProfilerContainer::getInstance().addProfiler(std::make_shared<poc::Profiler>(name, poc::ProfilerManager::getInstance()));
#define PROFILE_BLOCK_END poc::ProfilerContainer::getInstance().removeProfiler();
#define PROFILE_BLOCK_FREQUENCY(name) poc::ProfilerManager::getInstance().addCallTime(name, poc::clock::now());

#define PROFILE_FUNCTION PROFILE_BLOCK(__FUNCTION__)
#define PROFILE_FUNCTION_FREQUENCY PROFILE_BLOCK_FREQUENCY(__FUNCTION__)
#define PROFILE_GENERATE_REPORT poc::ProfilerManager::getInstance().generateReport();
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

#endif // __POC_H__

