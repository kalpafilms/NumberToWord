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

TEST_F(LookupEnTests, getWord_ShouldReturnFourteen_WhenPass14)
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

TEST_F(LookupEnTests, getWord_ShouldRaiseException_WhenPass100)
{
    const uint32_t INPUT{100};

    ASSERT_THROW(lookup.getWord(INPUT), std::invalid_argument);
}

/**
 * Tests for getThousandSeparator function
 */
TEST_F(LookupEnTests, getThousandSeparator_ShouldReturnThousand_WhenCalledOnce)
{
    const std::string EXPECTED{"thousand"};

    std::string separator = lookup.getThousandSeparator();

    ASSERT_EQ(separator, EXPECTED);
}

TEST_F(LookupEnTests, getThousandSeparator_ShouldReturnMillion_OnSecondCall)
{
    const std::string EXPECTED{"million"};

    lookup.getThousandSeparator();
    std::string separator = lookup.getThousandSeparator();

    ASSERT_EQ(separator, EXPECTED);
}

TEST_F(LookupEnTests, getThousandSeparator_ShouldReturnBillion_OnThirdCall)
{
    const std::string EXPECTED{"billion"};

    lookup.getThousandSeparator();
    lookup.getThousandSeparator();
    std::string separator = lookup.getThousandSeparator();

    ASSERT_EQ(separator, EXPECTED);
}

TEST_F(LookupEnTests, getThousandSeparator_ShouldRaiseException_OnFourthCall)
{
    lookup.getThousandSeparator();
    lookup.getThousandSeparator();
    lookup.getThousandSeparator();

    ASSERT_THROW(lookup.getThousandSeparator(), std::out_of_range);
}
