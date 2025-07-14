#pragma once

#ifdef NA_PLATFORM_WINDOWS
	#ifdef NA_BUILD_DLL
		#define NEBULARK_API __declspec(dllexport)
	#else
		#define NEBULARK_API __declspec(dllimport)	
	#endif // NA_BUILD_DLL
#else
	#error "Nebulark only supports Windows platform at the moment."
#endif // NA_PLATFORM_WINDOWS
