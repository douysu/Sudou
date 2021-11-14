#pragma once

#ifdef SUDOU_PLATFORM_WINDOWS
	#ifdef SUDOU_BUILD_DLL
		#define	SUDOU_API __declspec(dllexport)
	#else
		#define SUDOU_API __declspec(dllimport)
	#endif // SUDOU_BUILD_DLL
#else
	#define SUDOU_API
#endif // HZ_PLATFORM_WINDOWS
