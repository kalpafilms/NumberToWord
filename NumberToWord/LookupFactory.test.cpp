//
//  LookupFactory.test.cpp
//  N2WTests
//
//  Created by Joohyung Ryu on 2023-11-21.
//

#include <gtest/gtest.h>

#include "LookupFactory.hpp"

class LookupFactoryTests : public ::testing::Test
{
protected:
    template <typename Base>
    inline bool isInstanceOf(const Lookup *ptr)
    {
        return dynamic_cast<const Base *>(ptr) != nullptr;
    }

public:
    LookupFactoryTests() {}
    virtual ~LookupFactoryTests() {}

    LookupFactory lookupFactory;
};

/**
 * Tests for getLookupTableFor function
 */
TEST_F(LookupFactoryTests, getLookupTableFor_ShouldReturnNullPtr_WhenPassLanguageNone)
{
    const Language TARGET{Language::NONE};

    Lookup *lookup = lookupFactory.getLookupTableFor(TARGET);

    ASSERT_EQ(lookup, nullptr);
}

TEST_F(LookupFactoryTests, getLookupTableFor_ShouldReturnEnglishTable_WhenPassEnglishLanguage)
{
    const Language TARGET{Language::ENGLISH};

    Lookup *lookup = lookupFactory.getLookupTableFor(TARGET);

    ASSERT_TRUE(isInstanceOf<LookupEnglish>(lookup));
}

TEST_F(LookupFactoryTests, getLookupTableFor_ShouldReturnKoreanTable_WhenPassKoreanLanguage)
{
    const Language TARGET{Language::KOREAN};

    Lookup *lookup = lookupFactory.getLookupTableFor(TARGET);

    ASSERT_TRUE(isInstanceOf<LookupKorean>(lookup));
}
