#pragma once

#ifdef _MSC_VER
#define LIBMEM_DEMO_NOINLINE __declspec(noinline)
#else
#define LIBMEM_DEMO_NOINLINE __attribute__((noinline))
#endif
