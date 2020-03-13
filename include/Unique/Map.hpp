#ifndef __UNIQUE_MAP_HPP__
#define __UNIQUE_MAP_HPP__

// ─────────────────────────────────────────────────────────────
//                  INCLUDE
// ─────────────────────────────────────────────────────────────

#include <Unique/TMap.hpp>
#include <map>

// ─────────────────────────────────────────────────────────────
//                  DECLARATION
// ─────────────────────────────────────────────────────────────

namespace Unique {

// ─────────────────────────────────────────────────────────────
//                  CLASS
// ─────────────────────────────────────────────────────────────

template <class Key1, class Key2>
class Map : public TMap<std::map, std::map, Key1, Key2>
{
};

}

#endif