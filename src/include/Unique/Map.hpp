#ifndef __UNIQUE_MAP_HPP__
#define __UNIQUE_MAP_HPP__

// ─────────────────────────────────────────────────────────────
//                  INCLUDE
// ─────────────────────────────────────────────────────────────

// C Header

// C++ Header
#include <unordered_map>
#include <map>

// Dependencies Header

// Application Header
#include <Unique/Export.hpp>

// ─────────────────────────────────────────────────────────────
//                  DECLARATION
// ─────────────────────────────────────────────────────────────

UNIQUE_NAMESPACE_START

// ─────────────────────────────────────────────────────────────
//                  CLASS
// ─────────────────────────────────────────────────────────────

/**
 */
template <class Key1, class Key2>
class UNIQUE_API_ Map
{
public:
    typedef std::map<Key1, Key2> Key1Map;
    typedef std::unordered_map<Key2, Key1> Key2Map;

    typedef typename Key1Map::iterator Key1Iterator;
    typedef typename Key2Map::iterator Key2Iterator;

    typedef typename Key1Map::const_iterator Key1ConstIterator;
    typedef typename Key2Map::const_iterator Key2ConstIterator;

    typedef typename Key1Map::value_type Key1ValueType;
    typedef typename Key2Map::value_type Key2ValueType;

    typedef typename Key1Map::key_type Key1Type;
    typedef typename Key2Map::key_type Key2Type;

    typedef typename Key1Map::reverse_iterator Key1ReverseIterator;
    typedef typename Key1Map::const_reverse_iterator Key1ConstReverseIterator;
public:
    virtual ~Map() = default;
private:
    Key1Map _key1Map;
    Key2Map _key2Map;

public:
    const Key1Map& key1Map() const { return _key1Map; }
    const Key2Map& key2Map() const { return _key2Map; }

    // ──────── ITERATORS ──────────
public:
    /**
     * \brief Returns an iterator to the first element of the container
     * If the container is empty, the returned iterator will be equal to end().
     * \return Iterator to the first element.
     */
    Key1Iterator begin() noexcept { return _key1Map.begin(); }

    /**
     * \brief Returns an iterator to the element following the last element of the container.
     * This element acts as a placeholder; attempting to access it results in undefined behavior.
     * \return Iterator to the element following the last element.
     */
    Key1Iterator end() noexcept { return _key1Map.end(); }

    /**
     * \brief Returns an iterator to the first element of the container
     * If the container is empty, the returned iterator will be equal to end().
     * \return Iterator to the first element.
     */
    Key1ConstIterator begin() const noexcept { return _key1Map.cbegin(); }

    /**
     * \brief Returns an iterator to the element following the last element of the container.
     * This element acts as a placeholder; attempting to access it results in undefined behavior.
     * \return Iterator to the element following the last element.
     */
    Key1ConstIterator end() const noexcept { return _key1Map.cend(); }

    /**
     * \brief Returns an iterator to the first element of the container
     * If the container is empty, the returned iterator will be equal to end().
     * \return Iterator to the first element.
     */
    Key1ConstIterator cbegin() const noexcept { return _key1Map.cbegin(); }

    /**
     * \brief Returns an iterator to the element following the last element of the container.
     * This element acts as a placeholder; attempting to access it results in undefined behavior.
     * \return Iterator to the element following the last element.
     */
    Key1ConstIterator cend() const noexcept { return _key1Map.cend(); }
    /**
     * \brief Returns a reverse iterator to the first element of the reversed container.
     * It corresponds to the last element of the non-reversed container.
     * If the container is empty, the returned iterator is equal to rend().
     * \return Reverse iterator to the first element.
     */
    Key1ReverseIterator rbegin() noexcept { return _key1Map.rbegin(); }

    /**
     * \brief Returns a reverse iterator to the element following the last element of the reversed container.
     * It corresponds to the element preceding the first element of the non-reversed container.
     * This element acts as a placeholder, attempting to access it results in undefined behavior.
     * \return Reverse iterator to the element following the last element.
     */
    Key1ReverseIterator rend() noexcept { return _key1Map.rend(); }

    /**
     * \brief Returns a reverse iterator to the first element of the reversed container.
     * It corresponds to the last element of the non-reversed container.
     * If the container is empty, the returned iterator is equal to rend().
     * \return Reverse iterator to the first element.
     */
    Key1ConstReverseIterator rbegin() const noexcept { return _key1Map.crbegin(); }

    /**
     * \brief Returns a reverse iterator to the element following the last element of the reversed container.
     * It corresponds to the element preceding the first element of the non-reversed container.
     * This element acts as a placeholder, attempting to access it results in undefined behavior.
     * \return Reverse iterator to the element following the last element.
     */
    Key1ConstReverseIterator rend() const noexcept { return _key1Map.crend(); }

    /**
     * \brief Returns a reverse iterator to the first element of the reversed container.
     * It corresponds to the last element of the non-reversed container.
     * If the container is empty, the returned iterator is equal to rend().
     * \return Reverse iterator to the first element.
     */
    Key1ConstReverseIterator crbegin() const noexcept { return _key1Map.crbegin(); }

    /**
     * \brief Returns a reverse iterator to the element following the last element of the reversed container.
     * It corresponds to the element preceding the first element of the non-reversed container.
     * This element acts as a placeholder, attempting to access it results in undefined behavior.
     * \return Reverse iterator to the element following the last element.
     */
    Key1ConstReverseIterator crend() const noexcept { return _key1Map.crend(); }

public:
    /**
     * \brief Returns an iterator to the first element of the container
     * If the container is empty, the returned iterator will be equal to end().
     * \return Iterator to the first element.
     */
    Key1Iterator begin1() noexcept { return begin(); }

    /**
     * \brief Returns an iterator to the element following the last element of the container.
     * This element acts as a placeholder; attempting to access it results in undefined behavior.
     * \return Iterator to the element following the last element.
     */
    Key1Iterator end1() noexcept { return end(); }

    /**
     * \brief Returns an iterator to the first element of the container
     * If the container is empty, the returned iterator will be equal to end().
     * \return Iterator to the first element.
     */
    Key1ConstIterator begin1() const noexcept { return cbegin(); }

    /**
     * \brief Returns an iterator to the element following the last element of the container.
     * This element acts as a placeholder; attempting to access it results in undefined behavior.
     * \return Iterator to the element following the last element.
     */
    Key1ConstIterator end1() const noexcept { return cend(); }

    /**
     * \brief Returns an iterator to the first element of the container
     * If the container is empty, the returned iterator will be equal to end().
     * \return Iterator to the first element.
     */
    Key1ConstIterator cbegin1() const noexcept { return cbegin(); }

    /**
     * \brief Returns an iterator to the element following the last element of the container.
     * This element acts as a placeholder; attempting to access it results in undefined behavior.
     * \return Iterator to the element following the last element.
     */
    Key1ConstIterator cend1() const noexcept { return cend(); }

public:
    /**
     * \brief Returns an iterator to the first element of the container
     * If the container is empty, the returned iterator will be equal to end().
     * \return Iterator to the first element.
     */
    Key2Iterator begin2() noexcept { return _key2Map.begin(); }

    /**
     * \brief Returns an iterator to the element following the last element of the container.
     * This element acts as a placeholder; attempting to access it results in undefined behavior.
     * \return Iterator to the element following the last element.
     */
    Key2Iterator end2() noexcept { return _key2Map.end(); }

    /**
     * \brief Returns an iterator to the first element of the container
     * If the container is empty, the returned iterator will be equal to end().
     * \return Iterator to the first element.
     */
    Key2ConstIterator begin2() const noexcept { return _key2Map.cbegin(); }

    /**
     * \brief Returns an iterator to the element following the last element of the container.
     * This element acts as a placeholder; attempting to access it results in undefined behavior.
     * \return Iterator to the element following the last element.
     */
    Key2ConstIterator end2() const noexcept { return _key2Map.cend(); }

    /**
     * \brief Returns an iterator to the first element of the container
     * If the container is empty, the returned iterator will be equal to end().
     * \return Iterator to the first element.
     */
    Key2ConstIterator cbegin2() const noexcept { return _key2Map.cbegin(); }

    /**
     * \brief Returns an iterator to the element following the last element of the container.
     * This element acts as a placeholder; attempting to access it results in undefined behavior.
     * \return Iterator to the element following the last element.
     */
    Key2ConstIterator cend2() const noexcept { return _key2Map.cend(); }

    // ──────── CAPACITY ──────────

public:
    /** \brief Check if container is empty */
    bool empty() const noexcept { return _key1Map.empty(); }

    /** \brief  Get the number of element in the container */
    size_t size() const noexcept { return _key1Map.size(); }

    /** \brief returns the maximum possible number of elements */
    size_t max_size() const noexcept { return _key1Map.max_size(); }

    // ──────── MODIFIERS ──────────

public:
    /** \brief clears the contents */
    void clear()
    {
        _key1Map.clear();
        _key2Map.clear();
    }

private:
    template<typename KeyMap, typename KeyOtherMap>
    static std::pair<typename KeyMap::iterator, bool> T_insert(typename KeyMap::value_type value, KeyMap& keyMap, KeyOtherMap& keyOtherMap)
    {
        // ) Check that the second key isn't already present in other map
        const auto keyOtherIt = keyOtherMap.find(value.second);
        if (keyOtherIt != keyOtherMap.end())
            return std::make_pair(keyMap.find(keyOtherIt->second), false);

        // ) Insert in both map, only insert in other map if first map insert succeed
        const auto res = keyMap.insert(value);
        if (res.second)
            keyOtherMap.insert({ value.second, value.first });

        // ) Return the res
        return res;
    }

    template<typename KeyMap, typename KeyOtherMap>
    static typename KeyMap::iterator T_insert(typename KeyMap::const_iterator hint, typename KeyMap::value_type value, KeyMap& keyMap, KeyOtherMap& keyOtherMap)
    {
        // ) Check that the second key isn't already present in other map
        const auto keyOtherIt = keyOtherMap.find(value.second);
        if (keyOtherIt != keyOtherMap.end())
            return keyMap.find(keyOtherIt->second);

        // ) We need to check if there not already an element, in order not to insert in the second map if the first insert succeed
        auto res = keyMap.find(value.first);
        if(res == keyMap.end())
        {
            res = keyMap.insert(hint, value);
            if (res != keyMap.end())
                keyOtherMap.insert({ value.second, value.first });
        }

        // ) Return the res
        return res;
    }

public:
    /**
     * \brief Inserts value.
     * \param value element value to insert
     * \return Returns a pair consisting of an iterator to the inserted element (or to the element that prevented the insertion) and a bool denoting whether the insertion took place.
     */
    std::pair<Key1Iterator, bool> insert(Key1ValueType&& value) { return T_insert(value, _key1Map, _key2Map); }

    /**
     * \brief Inserts value.
     * \param value element value to insert
     * \return Returns a pair consisting of an iterator to the inserted element (or to the element that prevented the insertion) and a bool denoting whether the insertion took place.
     */
    std::pair<Key1Iterator, bool> insert(const Key1ValueType& value) { return T_insert(value, _key1Map, _key2Map); }

    /**
     * \brief Inserts value, using hint as a non-binding suggestion to where the search should start.
     * \param hint 	iterator, used as a suggestion as to where to insert the content
     * \param value element value to insert
     * \return Returns an iterator to the inserted element, or to the element that prevented the insertion.
     */
    Key1Iterator insert(Key1ConstIterator hint, const Key1ValueType& value) { return T_insert(hint, value, _key1Map, _key2Map); }

    /**
     * \brief Inserts value, using hint as a non-binding suggestion to where the search should start.
     * \param hint 	iterator, used as a suggestion as to where to insert the content
     * \param value element value to insert
     * \return Returns an iterator to the inserted element, or to the element that prevented the insertion.
     */
    Key1Iterator insert(Key1ConstIterator hint, Key1ValueType&& value) { return T_insert(hint, value, _key1Map, _key2Map); }

public:
    /**
     * \brief Inserts value.
     * \param value element value to insert
     * \return Returns a pair consisting of an iterator to the inserted element (or to the element that prevented the insertion) and a bool denoting whether the insertion took place.
     */
    std::pair<Key2Iterator, bool> insert(Key2ValueType&& value) { return T_insert(value, _key2Map, _key1Map); }

    /**
     * \brief Inserts value.
     * \param value element value to insert
     * \return Returns a pair consisting of an iterator to the inserted element (or to the element that prevented the insertion) and a bool denoting whether the insertion took place.
     */
    std::pair<Key2Iterator, bool> insert(const Key2ValueType& value) { return T_insert(value, _key2Map, _key1Map); }

    /**
     * \brief Inserts value, using hint as a non-binding suggestion to where the search should start.
     * \param hint 	iterator, used as a suggestion as to where to insert the content
     * \param value element value to insert
     * \return Returns an iterator to the inserted element, or to the element that prevented the insertion.
     */
    Key2Iterator insert(Key2ConstIterator hint, const Key2ValueType& value) { return T_insert(hint, value, _key2Map, _key1Map); }

    /**
     * \brief Inserts value, using hint as a non-binding suggestion to where the search should start.
     * \param hint 	iterator, used as a suggestion as to where to insert the content
     * \param value element value to insert
     * \return Returns an iterator to the inserted element, or to the element that prevented the insertion.
     */
    Key2Iterator insert(Key2ConstIterator hint, Key2ValueType&& value) { return T_insert(hint, value, _key2Map, _key1Map); }

private:
    template<typename KeyMap, typename KeyOtherMap>
    static typename KeyMap::iterator T_erase(typename KeyMap::const_iterator pos, KeyMap& keyMap, KeyOtherMap& keyOtherMap)
    {
        if(pos != keyMap.end())
        {
            keyOtherMap.erase(pos->second);
            return keyMap.erase(pos);
        }
        return keyMap.end();
    }
    template<typename KeyMap, typename KeyOtherMap>
    size_t T_erase(const typename KeyMap::key_type& key, KeyMap& keyMap, KeyOtherMap& keyOtherMap)
    {
        const auto it = keyMap.find(key);
        if(it != keyMap.end())
        {
            keyOtherMap.erase(it->second);
            return keyMap.erase(key);
        }
        return 0;
    }

public:
    /**
     * \brief Removes the element at pos.
     * \param pos iterator to the element to remove
     * \return Iterator following the last removed element.
     */
    Key1Iterator erase(Key1ConstIterator pos) { return T_erase(pos, _key1Map, _key2Map); }

    /**
     * \brief Removes the element (if one exists) with the key equivalent to key.
     * \param key value of the elements to remove
     * \return Number of elements removed.
     */
    size_t erase(const Key1Type& key) { return T_erase(key, _key1Map, _key2Map); }

public:
    /**
     * \brief Removes the element at pos.
     * \param pos iterator to the element to remove
     * \return Iterator following the last removed element.
     */
    Key2Iterator erase(Key2ConstIterator pos) { return T_erase(pos, _key2Map, _key1Map); }

    /**
     * \brief Removes the element (if one exists) with the key equivalent to key.
     * \param key value of the elements to remove
     * \return Number of elements removed.
     */
    size_t erase(const Key2Type& key) { return T_erase(key, _key2Map, _key1Map); }

private:
    template<typename Key, typename OtherKey, typename KeyMap, typename KeyOtherMap>
    bool T_move(const Key& key, const OtherKey& newKey, KeyMap& keyMap, KeyOtherMap& keyOtherMap)
    {
        // ) Iterator at index key. Used to get it's current key
        auto it = keyMap.find(key);

        // ) If the current other key is the same as the new one we want to move to, then we don't need to do anything
        const auto currentOtherKey = it->second;
        if (newKey == currentOtherKey)
            return true;

        // ) The current other iterator, the one we need to erase and reinsert
        const auto currentOtherIt = keyOtherMap.find(currentOtherKey);

        // ) Check that key is present
        if (it == keyMap.end())
            return false;
        if (currentOtherIt == keyOtherMap.end())
            return false;

        // ) Check that the new key is available in the container
        const auto newOtherIt = keyOtherMap.find(newKey);
        if (newOtherIt != keyOtherMap.end())
            return false;

        // ) For keyMap we just new to change second member but for other key, the map key change so we need to erase and insert
        it->second = newKey;
        keyOtherMap.erase(currentOtherIt);
        keyOtherMap.insert({ newKey, key });

        return true;
    }

    template<typename Key, typename KeyMap, typename KeyOtherMap>
    bool T_move(const Key& currentKey, const Key& newKey, KeyMap& keyMap, KeyOtherMap& keyOtherMap)
    {
        const auto currentIt = keyMap.find(currentKey);

        // ) Function fail if key isn't present
        if (currentIt == keyMap.end())
            return false;

        const auto newIt = keyMap.find(newKey);

        // ) Function fail if there is already something at the new id
        if (newIt != keyMap.end())
            return false;

        const auto otherCurrentKey = currentIt->second;
        // ) currentOtherIt should always be valid because currentIt exist
        const auto currentOtherIt = keyOtherMap.find(otherCurrentKey);

        currentOtherIt->second = newKey;
        keyMap.erase(currentIt);
        keyMap.insert({ newKey, otherCurrentKey });

        return true;
    }

public:
    /**
     * \brief move key2 at newKey
     * \param key2 Second key you want to move to newKey
     * \param newKey new associated key with key2
     * \return true if move success
     * false if there is already a key associated with newKey
     * false if key2 isn't present
     */
    bool move(const Key2& key2, const Key1& newKey) { return T_move(key2, newKey, _key2Map, _key1Map); }

    /**
     * \brief move key2 at newKey
     * \param key1 First key you want to move to newKey
     * \param newKey new associated key with key2
     * \return true if move success
     * false if there is already a key associated with newKey
     * false if key1 isn't present
     */
    bool move(const Key1& key1, const Key2& newKey) { return T_move(key1, newKey, _key1Map, _key2Map); }

    /**
     * \brief Change the key from currentKey to newKey
     * \param currentKey CurrentKey in Key1Map
     * \param newKey NewKey in Key1Map
     * \return true if move success
     * false if currentKey doesn't exist
     * false if newKey is already taken
     */
    bool move(const Key1& currentKey, const Key1& newKey) { return T_move(currentKey, newKey, _key1Map, _key2Map); }

    /**
     * \brief Change the key from currentKey to newKey
     * \param currentKey CurrentKey in Key2Map
     * \param newKey NewKey in Key2Map
     * \return true if move success
     * false if currentKey doesn't exist
     * false if newKey is already taken
     */
    bool move(const Key2& currentKey, const Key2& newKey) { return T_move(currentKey, newKey, _key2Map, _key1Map); }

private:
    template<typename Key, typename KeyMap, typename KeyOtherMap>
    bool T_swap(const Key& key1, const Key& key2, KeyMap& keyMap, KeyOtherMap& keyOtherMap)
    {
        const auto it1 = keyMap.find(key1);
        const auto it2 = keyMap.find(key2);

        const auto tempOtherKey1 = it1->second;
        const auto tempOtherKey2 = it2->second;

        const auto otherIt1 = keyOtherMap.find(it1->second);
        const auto otherIt2 = keyOtherMap.find(it2->second);

        it1->second = tempOtherKey2;
        it2->second = tempOtherKey1;

        otherIt1->second = key2;
        otherIt2->second = key1;

        return true;
    }

public:
    bool swap(const Key1& key, const Key1& otherKey) { return T_swap(key, otherKey, _key1Map, _key2Map); }
    bool swap(const Key2& key, const Key2& otherKey) { return T_swap(key, otherKey, _key2Map, _key1Map); }

    // ──────── LOOKUP ──────────

private:
    template<class Key, typename KeyMap>
    typename KeyMap::iterator T_find(const Key key, KeyMap& keyMap)
    {
        return keyMap.find(key);
    }

    template<class Key, typename KeyMap>
    typename KeyMap::const_iterator T_find(const Key key, KeyMap& keyMap) const
    {
        return keyMap.find(key);
    }

public:
    /**
     * \brief Finds an element with key equivalent to key.
     * \param key key value of the element to search for
     * \return Iterator to an element with key equivalent to key. If no such element is found, past-the-end (see end()) iterator is returned.
     */
    Key1Iterator find(const Key1& key) { return T_find(key, _key1Map); }

    /**
     * \brief Finds an element with key equivalent to key.
     * \param key key value of the element to search for
     * \return Iterator to an element with key equivalent to key. If no such element is found, past-the-end (see end()) iterator is returned.
     */
    Key1ConstIterator find(const Key1& key) const { return T_find(key, _key1Map); }
public:
    /**
     * \brief Finds an element with key equivalent to key.
     * \param key key value of the element to search for
     * \return Iterator to an element with key equivalent to key. If no such element is found, past-the-end (see end()) iterator is returned.
     */
    Key2Iterator find(const Key2& key) { return T_find(key, _key2Map); }

    /**
     * \brief Finds an element with key equivalent to key.
     * \param key key value of the element to search for
     * \return Iterator to an element with key equivalent to key. If no such element is found, past-the-end (see end()) iterator is returned.
     */
    Key2ConstIterator find(const Key2& key) const { return T_find(key, _key2Map); }

public:
    bool contains(const Key1& value) const { return find(value) != end1(); }
    bool contains(const Key2& value) const { return find(value) != end2(); }
};

UNIQUE_NAMESPACE_END

#endif // __UNIQUE_MAP_HPP__
