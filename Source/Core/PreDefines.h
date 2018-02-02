#pragma once

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <type_traits>
#include <queue>
#include <stack>

#define NSBEGIN namespace RTEngine {
#define NSEND	}

//////////////////////////////////////////////////////////////force inline
#ifndef FORCE_INLINE
#ifdef _DEBUG
#define FORCE_INLINE inline
#else
#if (defined(__GNUC__) && (__GNUC__ >= 4)) || defined(__llvm__)
#define FORCE_INLINE __attribute__((always_inline)) inline
#elif defined(_MSC_VER)
#define FORCE_INLINE __forceinline
#else
#define FORCE_INLINE inline
#endif
#endif
#endif//FORCE_INLINE