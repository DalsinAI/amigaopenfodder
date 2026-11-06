// Included before every source file (-include): what the GCC 16 stove's
// libstdc++ for the 68040 leaves out of <cstdlib> (it was configured
// without _GLIBCXX_USE_C99, though libnix has these). The AmiCradle Team.
// GPL 3 or later, like Open Fodder.
#ifndef AMIGA_PRELUDE_HPP
#define AMIGA_PRELUDE_HPP
#ifdef __cplusplus
#include <cstdlib>
#include <string>
namespace std {
using ::atoll;
using ::strtoll;
using ::strtoull;
using ::strtof;
using ::strtold;
using ::llabs;
// std::string's C99 conversions, which the same setting leaves out
inline long long stoll(const string& s, size_t* idx = nullptr, int base = 10)
{ const char* p = s.c_str(); char* e; long long r = ::strtoll(p, &e, base); if (idx) *idx = e - p; return r; }
inline unsigned long long stoull(const string& s, size_t* idx = nullptr, int base = 10)
{ const char* p = s.c_str(); char* e; unsigned long long r = ::strtoull(p, &e, base); if (idx) *idx = e - p; return r; }
inline long double stold(const string& s, size_t* idx = nullptr)
{ const char* p = s.c_str(); char* e; long double r = ::strtold(p, &e); if (idx) *idx = e - p; return r; }
}
#endif
#endif
