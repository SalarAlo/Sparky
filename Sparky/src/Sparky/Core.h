#pragma once

#ifdef SPY_PLATFORM_WINDOWS 

	#ifdef SPY_BUILD_DLL
		#define SPARKY_API __declspec(dllexport)
	#else
		#define SPARKY_API __declspec(dllimport)
	#endif
#else
	#error Sparky engine only supports Windows!
#endif
