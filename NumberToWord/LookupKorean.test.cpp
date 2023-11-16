//
//  LookupKorean.test.cpp
//  N2WTests
//
//  Created by Joohyung Ryu on 2023-11-14.
//

#include <gtest/gtest.h>

#include "LookupKorean.hpp"

class LookupKoTests : public ::testing::Test
{
public:
    LookupKoTests() {}
    virtual ~LookupKoTests() {}

    LookupKorean lookup;
};

/**
 * Tests for getSeparatorWord function
 */
TEST_F(LookupKoTests, getSeparatorWord_ShouldReturnMahn_OnFirstCall)
{
    const std::string EXPECTED{"만"};

    std::string separator = lookup.getSeparatorWord();

    ASSERT_EQ(separator, EXPECTED);
}

TEST_F(LookupKoTests, getSeparatorWord_ShouldReturnEok_OnSecondCall)
{
    const std::string EXPECTED{"억"};
    
    lookup.getSeparatorWord();
    std::string separator = lookup.getSeparatorWord();
    
    ASSERT_EQ(separator, EXPECTED);
}

TEST_F(LookupKoTests, getSeparatorWord_ShouldRaiseException_OnThirdCall)
{
    lookup.getSeparatorWord();
    lookup.getSeparatorWord();
    
    ASSERT_THROW(lookup.getSeparatorWord(), std::out_of_range);
}

/**
 * Tests for getZeroWord function
 */
TEST_F(LookupKoTests, getZeroWord_ShouldReturnYeong_OnCall)
{
    const std::string EXPECTED{"영"};

    std::string zero = lookup.getZeroWord();

    ASSERT_EQ(zero, EXPECTED);
}

/**
 * Tests for getSeparatorSize function
 */
TEST_F(LookupKoTests, getSeparatorSize_ShouldReturn4_OnCall)
{
    const uint8_t EXPECTED{4};

    uint8_t separatorSize = lookup.getSeparatorSize();

    ASSERT_EQ(separatorSize, EXPECTED);
}
