#ifndef __UNIQUE_EXPORT_HPP__
#define __UNIQUE_EXPORT_HPP__

// ─────────────────────────────────────────────────────────────
//                  DECLARATION
// ─────────────────────────────────────────────────────────────

#ifdef WIN32
    #ifdef UNIQUE_DLL_EXPORT  // Shared build
        #define UNIQUE_API_ __declspec(dllexport)
    #elif UNIQUE_STATIC       // No decoration when building staticlly
        #define UNIQUE_API_
    #else                       // Link to lib
        #define UNIQUE_API_ __declspec(dllimport)
    #endif
#else
    #define UNIQUE_API_
#endif // WIN32

#ifdef UNIQUE_USE_NAMESPACE

    #ifndef UNIQUE_NAMESPACE
        #define UNIQUE_NAMESPACE Unique
    #endif // ifndef UNIQUE_NAMESPACE

    #define UNIQUE_NAMESPACE_START namespace UNIQUE_NAMESPACE {
    #define UNIQUE_NAMESPACE_END }
    #define UNIQUE_USING_NAMESPACE using namespace UNIQUE_NAMESPACE;

#else // UNIQUE_USE_NAMESPACE

    #undef UNIQUE_NAMESPACE
    #define UNIQUE_NAMESPACE
    #define UNIQUE_NAMESPACE_START
    #define UNIQUE_NAMESPACE_END
    #define UNIQUE_USING_NAMESPACE

#endif // UNIQUE_USE_NAMESPACE

#endif // __UNIQUE_EXPORT_HPP__
