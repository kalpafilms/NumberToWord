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
 * Test for getWordFrom function
 */
TEST_F(LookupKoTests, getWordFrom_ShouldReturnEmptyString_WhenPass0)
{
    const uint32_t INPUT{0};
    const std::string EXPECTED{""};

    std::string word = lookup.getWordFrom(INPUT);

    ASSERT_EQ(word, EXPECTED);
}

TEST_F(LookupKoTests, getWordFrom_ShouldReturnSam_WhenPass3)
{
    const uint32_t INPUT{3};
    const std::string EXPECTED{"삼"};

    std::string word = lookup.getWordFrom(INPUT);

    ASSERT_EQ(word, EXPECTED);
}

TEST_F(LookupKoTests, getWordFrom_ShouldReturnSaSibI_WhenPass42)
{
    const uint32_t INPUT{42};
    const std::string EXPECTED{"사십이"};

    std::string word = lookup.getWordFrom(INPUT);

    ASSERT_EQ(word, EXPECTED);
}

TEST_F(LookupKoTests, getWordFrom_ShouldReturnIlBeag_WhenPass100)
{
    const uint32_t INPUT{100};
    const std::string EXPECTED{"일백"};

    std::string word = lookup.getWordFrom(INPUT);

    ASSERT_EQ(word, EXPECTED);
}

TEST_F(LookupKoTests, getWordFrom_ShouldReturnGuCheonPalBeagYuk_WhenPass1234)
{
    const uint32_t INPUT{9806};
    const std::string EXPECTED{"구천팔백육"};

    std::string word = lookup.getWordFrom(INPUT);

    ASSERT_EQ(word, EXPECTED);
}

TEST_F(LookupKoTests, getWordFrom_ShouldRaiseException_WhenPass10000)
{
    const uint32_t INPUT{10000};

    ASSERT_THROW(lookup.getWordFrom(INPUT), std::invalid_argument);
}

/**
 * Tests for getSeparatorWord function
 */
TEST_F(LookupKoTests, getSeparatorWord_ShouldReturnMan_OnFirstCall)
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
