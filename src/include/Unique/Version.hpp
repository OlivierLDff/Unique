#ifndef __UNIQUE_COMMON_HPP__
#define __UNIQUE_COMMON_HPP__

// ─────────────────────────────────────────────────────────────
//                  INCLUDE
// ─────────────────────────────────────────────────────────────

// C Header
#include <cstdint>

// We need to undef this to keep compatibility with UNIX systems
#undef major
#undef minor

// C++ Header

// Dependencies Header

// Application Header
#include <Unique/Export.hpp>

// ─────────────────────────────────────────────────────────────
//                  DECLARATION
// ─────────────────────────────────────────────────────────────

UNIQUE_NAMESPACE_START

class UNIQUE_API_ Version
{
    // ──────── CONSTRUCTOR ────────────────

    // ──────── ATTRIBUTES ────────────────
public:
    static uint32_t major();
    static uint32_t minor();
    static uint32_t patch();
    static uint32_t tag();
    static const char* readable();
};

UNIQUE_NAMESPACE_END

#endif
