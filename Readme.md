# Unique

[![](https://github.com/OlivierLDff/Unique/workflows/CI/badge.svg)](https://github.com/OlivierLDff/Unique/actions?query=workflow%3ACI)

Unique library provide helper class to create unique stuff.

## IdProvider

`IdProvider<T, T min, T max >` is a class that provide a unique id on request. This is a template class that take 3 parameters:

* **T**: The type of the id you want to use. For example `uint32_t`.
* **min**: The minimum id available. For example 1.
* **max**: The maximum id available. For example 4582682.

### Api

#### TakeId/TakeNextId

To take an id you have 2 functions available:

* `bool takeId(const T id)` : Take an id from the provider. This function return true if the id was available and false if it was already taken.
* `T takeNextId()`: Take the next available id.

```c++
#include <Unique/IdProvider.hpp>
int main()
{
    IdProvider<uint32_t, 1, 0xFFFFFFFF> idProvider;

    // Id1 == 1
    const auto id1 = idProvider.takeNextId();
    // Id2 == 2
    const auto id2 = idProvider.takeNextId();
    // idTaken == true
    const auto idTaken = idProvider.takeId(5);
    // idTaken2 == false
    const auto idTaken2 = idProvider.takeId(2);
    // Id3 == 3
    const auto id3 = idProvider.takeNextId();
    // Id4 == 4
    const auto id4 = idProvider.takeNextId();
    // Id6 == 6
    const auto id6 = idProvider.takeNextId();
}
```

> If you just want to know what is the next id available without taking it, then you can use the function `T getFirstIdAvailable() const`. If you really want to keep the id you can then call `takeId` with the result.
>
> Note: Id will always be taken incrementally.

#### ReleaseId

Every taken id can be released.

* `void releaseId(const T id)`: Release an id for it to be available in with `takeNextId` again.
* `void clear()`: Release all ids.

```c++
#include <Unique/IdProvider.hpp>
int main()
{
    IdProvider<uint32_t, 1, 0xFFFFFFFF> idProvider;

    // Id1 == 1
    const auto id1 = idProvider.takeNextId();
    idProvider.releaseId(id1);
    // Id2 == 1
    const auto id2 = idProvider.takeNextId();
    idProvider.clear();
    // Id3 == 1
    const auto id3 = idProvider.takeNextId();
}
```

#### IsIdAvailable

You can check if an id is available with:

* `bool isIdAvailable(const T id) const`: This will tell you if an id is ready to be taken or not.

## Map

A Unique Map works like a map from the std library except that both keys needs to be unique. Internally the object use 2 maps that cross references each keys. So for the lookup each key can be used for faster lookup. The map with the fastest lookup time will always be used.

Insertion and deletion are more expensive because there is 2 maps instead of just one.

The api behave the same than with a standard map.

If you want to iterate on the second key you should use begin2 and end2 functions.

This class is intended to be used in context where key1 is an id and key2 is a pointer to an object.

## Build

Simply clone then run cmake.

```bash
git clone https://github.com/OlivierLdff/Unique.git
cd Unique && mkdir build && cd build
cmake ..
cmake --build . --config Release
```

### Tests

Tests depends on google tests. They are build by default so you just need to run:

```bash
ctest -C Release
```

> For now only IdProvider is fully covered. I will add Map test. Maybe. Someday.

### CMake Parameters

- **UNIQUE_TARGET** : Library target name. *Default : "Unique"*
- **UNIQUE_PROJECT** : Project name. *Default : "Unique"*
- **UNIQUE_ENABLE_TESTS** : Build Unique Test executable [ON OFF]. *Default: OFF*.

## Authors

- [Olivier Le Doeuff](https://github.com/OlivierLDff)