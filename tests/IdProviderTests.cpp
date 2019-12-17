// C++ Header

// gtest framework
#include <gtest/gtest.h>

// Unique
#include <Unique/IdProvider.hpp>

UNIQUE_USING_NAMESPACE;

class UniqueIdProviderTests : public ::testing::Test
{
public:
    UniqueIdProviderTests() : Test(), base(idProvider.MIN) {}
    virtual ~UniqueIdProviderTests() = default;
protected:
    void SetUp() override
    {
    }

    void TearDown() override
    {
    }
public:
    IdProvider<uint32_t, 1, 0xFFFFFFFF> idProvider;
    const uint32_t base;
};

TEST_F(UniqueIdProviderTests, takeNextId)
{
    ASSERT_EQ(idProvider.countOfAvailableIds(), 0);

    ASSERT_EQ(base, idProvider.takeNextId());
    ASSERT_EQ(base + 1, idProvider.takeNextId());
    ASSERT_EQ(base + 2, idProvider.takeNextId());
    ASSERT_EQ(base + 3, idProvider.takeNextId());
    ASSERT_EQ(base + 4, idProvider.takeNextId());
    ASSERT_EQ(base + 5, idProvider.takeNextId());

    idProvider.clear();
    ASSERT_EQ(idProvider.countOfAvailableIds(), 0);

    ASSERT_EQ(base, idProvider.takeNextId());
    ASSERT_EQ(base + 1, idProvider.takeNextId());
    ASSERT_EQ(base + 2, idProvider.takeNextId());
    ASSERT_EQ(base + 3, idProvider.takeNextId());
    ASSERT_EQ(base + 4, idProvider.takeNextId());
    ASSERT_EQ(base + 5, idProvider.takeNextId());

    idProvider.releaseId(base + 1);
    idProvider.releaseId(base + 4);

    ASSERT_EQ(idProvider.countOfAvailableIds(), 2);

    ASSERT_EQ(base + 1, idProvider.takeNextId());
    ASSERT_EQ(base + 4, idProvider.takeNextId());
    ASSERT_EQ(base + 6, idProvider.takeNextId());
    ASSERT_EQ(base + 7, idProvider.takeNextId());

    idProvider.releaseId(base + 7);
    idProvider.releaseId(base + 6);

    ASSERT_EQ(idProvider.countOfAvailableIds(), 0);

    ASSERT_EQ(base + 6, idProvider.takeNextId());
    ASSERT_EQ(base + 7, idProvider.takeNextId());

    idProvider.releaseId(base + 1);
    idProvider.releaseId(base + 4);
    idProvider.releaseId(base + 6);

    ASSERT_EQ(idProvider.countOfAvailableIds(), 3);
    idProvider.clear();
    ASSERT_EQ(idProvider.countOfAvailableIds(), 0);
}

TEST_F(UniqueIdProviderTests, takeId)
{
    ASSERT_TRUE(idProvider.takeId(base + 4));
    ASSERT_EQ(idProvider.countOfAvailableIds(), 4);
    ASSERT_EQ(base, idProvider.takeNextId());
    ASSERT_EQ(base + 1, idProvider.takeNextId());
    ASSERT_EQ(base + 2, idProvider.takeNextId());
    ASSERT_EQ(base + 3, idProvider.takeNextId());
    ASSERT_EQ(idProvider.countOfAvailableIds(), 0);
    ASSERT_EQ(base + 5, idProvider.takeNextId());

    idProvider.releaseId(base + 4);
    idProvider.releaseId(base + 5);
    idProvider.releaseId(base + 3);

    ASSERT_EQ(base + 3, idProvider.takeNextId());

    idProvider.clear();
    ASSERT_TRUE(idProvider.takeId(base + 4));
    idProvider.releaseId(base + 4);
    ASSERT_EQ(idProvider.countOfAvailableIds(), 0);
    ASSERT_EQ(base, idProvider.takeNextId());

    idProvider.clear();
    ASSERT_TRUE(idProvider.takeId(base));
    ASSERT_TRUE(idProvider.takeId(base + 10));
    ASSERT_EQ(idProvider.countOfAvailableIds(), 9);
    idProvider.releaseId(base + 10);
    ASSERT_EQ(base + 1, idProvider.takeNextId());
}

TEST_F(UniqueIdProviderTests, takeIdBenchmark)
{
    ASSERT_TRUE(idProvider.takeId(10000));
    ASSERT_EQ(idProvider.countOfAvailableIds(), 10000 - 1);
}
