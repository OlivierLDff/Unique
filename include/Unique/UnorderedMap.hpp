#ifndef __UNIQUE_UNORDERED_MAP_HPP__
#define __UNIQUE_UNORDERED_MAP_HPP__

// ─────────────────────────────────────────────────────────────
//                  INCLUDE
// ─────────────────────────────────────────────────────────────

#include <Unique/TMap.hpp>
#include <unordered_map>

// ─────────────────────────────────────────────────────────────
//                  DECLARATION
// ─────────────────────────────────────────────────────────────

namespace Unique {

// ─────────────────────────────────────────────────────────────
//                  CLASS
// ─────────────────────────────────────────────────────────────

template <class Key1, class Key2>
class UnorderedMap : public TMap<std::unordered_map, std::unordered_map, Key1, Key2>
{
};

}

#endif
