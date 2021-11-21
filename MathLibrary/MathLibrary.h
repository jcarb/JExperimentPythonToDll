#pragma once

//https://docs.microsoft.com/en-us/cpp/build/walkthrough-creating-and-using-a-dynamic-link-library-cpp?view=msvc-160


#ifdef MATHLIBRARY_EXPORTS                      // 'PROJECT_NAME'_EXPORTS will be created when DLL project is built
#define MATHLIBRARY_API __declspec(dllexport)   // dllexport tells compiler and linker to export function/variable for use by other apps
#else
#define MATHLIBRARY_API __declspec(dllimport)
#endif

struct sampleStruct
{
	int Param1;
	int Param2;
};

// This is the fibonacci sequence
extern "C" MATHLIBRARY_API void fibonacci_init(const unsigned long long a, const unsigned long long b);

// Find next value in the sequence
extern "C" MATHLIBRARY_API bool fibonacci_next();

// Get current value in the sequence
extern "C" MATHLIBRARY_API unsigned long long fibonacci_current();

// Get the position of the current value in the sequence
extern "C" MATHLIBRARY_API unsigned fibonacci_index();

extern "C" MATHLIBRARY_API int readStruct(sampleStruct * thisSample);























