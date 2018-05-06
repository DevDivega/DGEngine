#ifndef DGENGINE_DGENGINE_HPP
#define DGENGINE_DGENGINE_HPP

#include "Defines/Types.hpp"

#ifdef DGE_PLATFORM_WINDOWS
	#ifdef DGE_DLL
		#define DGE_API __declspec(dllexport)
	#else
		#define DGE_API __declspec(dllimport)
	#endif
#else
	#define DGE_API
#endif

#define ASSERT(x) if (!(x)) __debugbreak();

#endif // !DGENGINE_DGENGINE_HPP
