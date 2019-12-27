#ifndef __UNIQUE_ID_PROVIDER_HPP__
#define __UNIQUE_ID_PROVIDER_HPP__

// ─────────────────────────────────────────────────────────────
//                  INCLUDE
// ─────────────────────────────────────────────────────────────

// C Header

// C++ Header
#include <cassert>
#include <set>

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

template <typename T, T min, T max >
class UNIQUE_API_ IdProvider
{
    // ──────── DEFAULTS ──────────
public:
    const T MIN = min;
    const T MAX = max;

    // Static assert if we are using c++17
#if __cplusplus > 201703L
    static_assert(min < max);
#endif

    static constexpr void assert_id(const T id);

private:
    /** Next id to return. It is always returned then incremented */
    T _idCounter = min;
    /** Available ids before idCounter */
    std::set<T> _availableIds;
    size_t _takenIdCounter = 0;

private:
    /** Recursively erase available ids in the available list. Recursion happen inside a while loop to avoid stack overflow */
    void eraseAvailableId(typename std::set<T>::iterator it);

    // ──────── C++ API ──────────
public:
    /** Force to increment idCounter if the id is >, or remove it from _availableIds.
     * If the id isn't found in _available and id is < _idCounter then the function will fail
     * \param id Value between _minId included and _maxId excluded. The function will assert otherwise
     * \return false if id is inferior from _idCounter and value isn't present in _availableIds
     */
    bool takeId(const T id);

    /** Take the next available id.
     * \return _idCounter if _availableIds is empty, or the cheapest value to remove from _availableIds.
     * Value will be between _minId and _maxId */
    T takeNextId();

    /**
     * \brief Get the first id available in the list, or 0 if there are no id available in the id stack.
     * This function doesn't remove the id from the stack. You should use `takeId` for that
     * \return First id available in _availableIds or 0 if no ids available.
     */
    T getFirstIdAvailable() const;

    /**
     * \brief Get the next id available. So either calling getFirstIdAvailable if there is some _availableIds
     * Otherwise return the valid of idCounter.
     * This function doesn't increment the idCounter or take any id.
     */
    T getNextId() const;

    /**
     * \brief Release an id to make it available to takeNextId again.
     * The function assert if id isn't bound correctly or if value already have been released
     * This behavior help to track bugs or misbehavior during dev
     * \param id Value between _minId included and _maxId excluded. The function will assert otherwise
     */
    void releaseId(const T id);

    /**
     * \brief Get if an id is used in the _availableIds stack.
     * \param id Value between _minId included and _maxId excluded. The function will assert otherwise
     * \return true if the value if present in _availableIds
     */
    bool isIdAvailable(const T id) const;

    /**
     * \brief Get if an id is taken
     * \param id Value between _minId included and _maxId excluded. The function will assert otherwise
     * \return true if the value isn't present in _availableId and the value is inferior to idCounter
     */
    bool isIdTaken(const T id) const;

    /**
     * \brief Count of available id before _idCounter
     * \return Size of _availableIds. This function is mainly tests
     */
    size_t countOfAvailableIds() const;

    /**
     * \brief Get if _availableIds is empty
     * \return True if there are no available ids
     */
    bool availableIdsEmpty() const;

    /** Get the count of taken ids */
    size_t countOfTakenIds() const;

    /**
     * \brief Clear the counter and reset everything to initialization
     * It can be seen as a reset function
     */
    void clear();
};

template <typename T, T min, T max>
constexpr void IdProvider<T, min, max>::assert_id(const T id)
{
    assert(id >= min);
    assert(id < max);
}

template <typename T, T min, T max>
void IdProvider<T, min, max>::eraseAvailableId(typename std::set<T>::iterator it)
{
    assert_id(it != _availableIds.end());
    do
    {
        const auto id = *it;
        assert_id(id);

        _availableIds.erase(it);

        if ((_idCounter > MIN) && (id == _idCounter - 1))
        {
            --_idCounter;
            if ((_idCounter > MIN))
                it = _availableIds.find(_idCounter - 1);
            else
                break;
        }
        else
            break;
    }
    while (it != _availableIds.end());
}

template <typename T, T min, T max>
bool IdProvider<T, min, max>::takeId(const T id)
{
    // ) Always assert the id to find bugs asap in debug
    assert_id(id);
    assert_id(_idCounter);

    // ) If we want to take _idCounter we can return it
    if (id == _idCounter)
    {
        // ) We simply increment it for next takeNextId to work
        ++_idCounter;

        // ) Keep track of every id taken
        ++_takenIdCounter;

        return true;
    }

    // ) We want a value that is upper to id Counter, we insert a range from _idCounter to (id-1)
    if (id > _idCounter)
    {
        for (auto i = _idCounter; i < id; ++i)
        {
            // ) Value that are > _idCounter should never be inside _availableIds
            assert(_availableIds.find(i) == _availableIds.end());
            _availableIds.insert(_availableIds.end(), i);
        }
        _idCounter = id + 1;

        // ) Keep track of every id taken
        ++_takenIdCounter;

        return true;
    }

    // ) We need to look if id is available in _availableIds
    const auto it = _availableIds.find(id);
    // )
    if (it == _availableIds.end())
        return false;

    eraseAvailableId(it);

    // ) Keep track of every id taken
    ++_takenIdCounter;
    return true;
}

template <typename T, T min, T max>
T IdProvider<T, min, max>::takeNextId()
{
    // ) If no ids are available to consume then we increment the counter
    if (_availableIds.empty())
    {
        // ) We can't have idCounter >= the maxId. Because it mean we reached maximum memory available, we need to assert
        assert(_idCounter < MAX);

        // ) Keep track of every id taken
        ++_takenIdCounter;

        return _idCounter++;
    }

    // Get the back value for fast remove
    const auto it = _availableIds.begin();
    const auto id = *it;
    _availableIds.erase(it);

    // ) Keep track of every id taken
    ++_takenIdCounter;
    return id;
}

template <typename T, T min, T max>
T IdProvider<T, min, max>::getFirstIdAvailable() const
{
    return countOfAvailableIds() ? *_availableIds.begin() : 0;
}

template <typename T, T min, T max>
T IdProvider<T, min, max>::getNextId() const
{
    const auto firstAvailableId = getFirstIdAvailable();
    return firstAvailableId ? firstAvailableId : _idCounter;
}

template <typename T, T min, T max>
void IdProvider<T, min, max>::releaseId(const T id)
{
    // ) Always assert the id to find bugs asap in debug
    assert_id(id);

    // We can't release a non present id.
    // If assert here instead of ignoring the case because
    // it means that something got wrong. idCounter should always be greater that any present id
    assert(_idCounter > id);

    // ) If the id to release is the same as the id Counter,
    // ie the id to release is the one got with getAvailableIdAndIncrement last call
    // Then we simply decrement our counter
    // ) Otherwise we keep track in our available id set
    if ((_idCounter > MIN) && _idCounter - 1 == id)
    {
        // ) We need to look if id is available in _availableIds
        --_idCounter;
        if ((_idCounter > MIN))
        {
            const auto it = _availableIds.find(_idCounter - 1);
            if (it != _availableIds.end())
                eraseAvailableId(it);
        }
    }
    else
    {
        // ) Assert that the value is unique
        assert(!isIdAvailable(id));
        // ) Simply push back the available id in the set
        _availableIds.insert(id);
    }

    assert(_takenIdCounter > 0);
    --_takenIdCounter;
}

template <typename T, T min, T max>
bool IdProvider<T, min, max>::isIdAvailable(const T id) const
{
    // ) Always assert the id to find bugs asap in debug
    assert_id(id);

    return id >= _idCounter || _availableIds.find(id) != _availableIds.end();
}

template <typename T, T min, T max>
bool IdProvider<T, min, max>::isIdTaken(const T id) const
{
    return !isIdAvailable(id);
}

template <typename T, T min, T max>
size_t IdProvider<T, min, max>::countOfAvailableIds() const
{
    return _availableIds.size();
}

template <typename T, T min, T max>
bool IdProvider<T, min, max>::availableIdsEmpty() const
{
    return  _availableIds.empty();
}

template <typename T, T min, T max>
size_t IdProvider<T, min, max>::countOfTakenIds() const
{
    return _takenIdCounter;
}

template <typename T, T min, T max>
void IdProvider<T, min, max>::clear()
{
    // ) Clear the idCounter and the available id array
    _idCounter = MIN;
    _availableIds.clear();
    _takenIdCounter = 0;
}

UNIQUE_NAMESPACE_END

#endif // __UNIQUE_ID_PROVIDER_HPP__
