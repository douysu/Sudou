#pragma once

#include "config.h"

#ifdef SUDOU_PLATFORM_WINDOWS
	#ifdef SUDOU_BUILD_DLL
		#define	SUDOU_API __declspec(dllexport)
	#else
		#define SUDOU_API __declspec(dllimport)
	#endif // SUDOU_BUILD_DLL
#else
	#define SUDOU_API
#endif // SD_PLATFORM_WINDOWS

#ifdef _DEBUG
	#define SD_ENABLE_ASSERTS
#endif

#ifdef SD_ENABLE_ASSERTS
	#define SD_ASSERT(x, ...) { if(!(x)) { SD_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define SD_CORE_ASSERT(x, ...) { if(!(x)) { SD_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define SD_ASSERT(x, ...)
	#define SD_CORE_ASSERT(x, ...)
#endif


#define BIT(x) (1 << x)
#define SD_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)