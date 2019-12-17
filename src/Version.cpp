// ─────────────────────────────────────────────────────────────
//                  INCLUDE
// ─────────────────────────────────────────────────────────────

// C Header

// C++ Header

// Dependencies Header

// Application Header
#include <Unique/Version.hpp>

// ─────────────────────────────────────────────────────────────
//                  DECLARATION
// ─────────────────────────────────────────────────────────────

UNIQUE_USING_NAMESPACE

// ─────────────────────────────────────────────────────────────
//                  FUNCTIONS
// ─────────────────────────────────────────────────────────────
//
#define xstr(s) str(s)
#define str(s) #s

constexpr auto READABLE = xstr(UNIQUE_VERSION_MAJOR) "." xstr(UNIQUE_VERSION_MINOR) "." xstr(UNIQUE_VERSION_PATCH) "." xstr(UNIQUE_VERSION_TAG_HEX);

uint32_t Version::major()
{
    return UNIQUE_VERSION_MAJOR;
}

uint32_t Version::minor()
{
    return UNIQUE_VERSION_MINOR;
}

uint32_t Version::patch()
{
    return UNIQUE_VERSION_PATCH;
}

uint32_t Version::tag()
{
    return UNIQUE_VERSION_TAG_HEX;
}

const char* Version::readable()
{
    return READABLE;
}
