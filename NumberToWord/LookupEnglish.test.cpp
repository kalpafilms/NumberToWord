//
//  LookupEnglish.test.cpp
//  N2WTests
//
//  Created by Joohyung Ryu on 2023-10-29.
//

#include <gtest/gtest.h>

#include "LookupEnglish.hpp"

class LookupEnTests : public ::testing::Test
{
public:
    LookupEnglish lookup;

    LookupEnTests(){};
    virtual ~LookupEnTests(){};
};

/**
 * Tests for getWord function
 */
TEST_F(LookupEnTests, getWord_ShouldReturnZero_WhenPass0)
{
    const uint32_t INPUT{0};
    const std::string EXPECTED{"zero"};

    std::string word = lookup.getWord(INPUT);

    ASSERT_EQ(word, EXPECTED);
}

TEST_F(LookupEnTests, getWord_ShouldReturnOne_WhenPass1)
{
    const uint32_t INPUT{1};
    const std::string EXPECTED{"one"};

    std::string word = lookup.getWord(INPUT);

    ASSERT_EQ(word, EXPECTED);
}

TEST_F(LookupEnTests, getWord_ShouldReturnForteen_WhenPass14)
{
    const uint32_t INPUT{14};
    const std::string EXPECTED{"fourteen"};

    std::string word = lookup.getWord(INPUT);

    ASSERT_EQ(word, EXPECTED);
}

TEST_F(LookupEnTests, getWord_ShouldReturnTwenty_WhenPass20)
{
    const uint32_t INPUT{20};
    const std::string EXPECTED{"twenty"};

    std::string word = lookup.getWord(INPUT);

    ASSERT_EQ(word, EXPECTED);
}

TEST_F(LookupEnTests, getWord_ShouldReturnFortyTwo_WhenPass42)
{
    const uint32_t INPUT{42};
    const std::string EXPECTED{"forty-two"};

    std::string word = lookup.getWord(INPUT);

    ASSERT_EQ(word, EXPECTED);
}

TEST_F(LookupEnTests, getWord_ShoudRaiseException_WhenPass100)
{
    const uint32_t INPUT{100};

    ASSERT_THROW(lookup.getWord(INPUT), std::invalid_argument);
}
