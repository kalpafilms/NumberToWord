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
TEST_F(LookupEnTests, getWord_ShouldReturnEmptyString_WhenPass0)
{
    const uint32_t INPUT{0};
    const std::string EXPECTED{""};

    std::string word = lookup.getWord(INPUT);

    ASSERT_EQ(word, EXPECTED);
}

TEST_F(LookupEnTests, getWord_ShouldReturnThree_WhenPass3)
{
    const uint32_t INPUT{3};
    const std::string EXPECTED{"three"};
    
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

TEST_F(LookupEnTests, getWord_ShouldReturnOneHundred_WhenPass100)
{
    const uint32_t INPUT{100};
    const std::string EXPECTED{"one hundred"};

    std::string word = lookup.getWord(INPUT);

    ASSERT_EQ(word, EXPECTED);
}

TEST_F(LookupEnTests, getWord_ShouldReturnNineHundredNinetyNine_WhenPass999)
{
    const uint32_t INPUT{999};
    const std::string EXPECTED{"nine hundred ninety-nine"};

    std::string word = lookup.getWord(INPUT);

    ASSERT_EQ(word, EXPECTED);
}

/**
 * Tests for getWordUnderThousand function
 */
TEST_F(LookupEnTests, getWordUnderThousand_ShouldReturnZero_WhenPass0)
{
    const uint32_t INPUT{0};
    const std::string EXPECTED{"zero"};

    std::string word = lookup.getWordUnderThousand(INPUT);

    ASSERT_EQ(word, EXPECTED);
}

TEST_F(LookupEnTests, getWordUnderThousand_ShouldReturnOne_WhenPass1)
{
    const uint32_t INPUT{1};
    const std::string EXPECTED{"one"};

    std::string word = lookup.getWordUnderThousand(INPUT);

    ASSERT_EQ(word, EXPECTED);
}

TEST_F(LookupEnTests, getWordUnderThousand_ShouldReturnFourteen_WhenPass14)
{
    const uint32_t INPUT{14};
    const std::string EXPECTED{"fourteen"};

    std::string word = lookup.getWordUnderThousand(INPUT);

    ASSERT_EQ(word, EXPECTED);
}

TEST_F(LookupEnTests, getWordUnderThousand_ShouldReturnTwenty_WhenPass20)
{
    const uint32_t INPUT{20};
    const std::string EXPECTED{"twenty"};

    std::string word = lookup.getWordUnderThousand(INPUT);

    ASSERT_EQ(word, EXPECTED);
}

TEST_F(LookupEnTests, getWordUnderThousand_ShouldReturnFortyTwo_WhenPass42)
{
    const uint32_t INPUT{42};
    const std::string EXPECTED{"forty-two"};

    std::string word = lookup.getWordUnderThousand(INPUT);

    ASSERT_EQ(word, EXPECTED);
}

TEST_F(LookupEnTests, getWordUnderThousand_ShouldRaiseException_WhenPass100)
{
    const uint32_t INPUT{100};

    ASSERT_THROW(lookup.getWordUnderThousand(INPUT), std::invalid_argument);
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

/**
 * Tests for getSeparatorSize function
 */
TEST_F(LookupEnTests, getSeparatorSize_ShouldReturn3_OnCall)
{
    const uint8_t EXPECTED{3};

    uint8_t separatorSize = lookup.getSeparatorSize();

    ASSERT_EQ(separatorSize, EXPECTED);
}
