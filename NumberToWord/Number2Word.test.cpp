//
//  Number2Word.test.cpp
//  N2WTests
//
//  Created by Joohyung Ryu on 2023-10-26.
//

#include <algorithm>
#include <gtest/gtest.h>

#include "Number2Word.hpp"

class N2WTests : public ::testing::Test
{
protected:
    // Helper for evaluating the transform() function
    void evaluateTransform(const std::string &input, const std::string &expected)
    {
        std::stringstream buffer;
        // Save std::cout buffer
        std::streambuf *sbuf = std::cout.rdbuf();
        // Redirect std::cout to the std::stringstream buffer
        std::cout.rdbuf(buffer.rdbuf());

        n2w.transform(input);
        std::string output = buffer.str();
        // Trim new line character
        output.erase(std::remove(output.begin(), output.end(), '\n'), output.cend());

        // Restore std::cout to original one
        std::cout.rdbuf(sbuf);

        ASSERT_EQ(output, expected);
    };

public:
    Number2Word n2w;

    N2WTests(){};
    virtual ~N2WTests(){};
};

/**
 * Tests for transform function
 */
TEST_F(N2WTests, transform_ShouldPrintOutZero_WhenPass0)
{
    const std::string INPUT{"0"};
    const std::string EXPECTED{"zero"};

    evaluateTransform(INPUT, EXPECTED);
}

TEST_F(N2WTests, transform_ShouldPrintOutOne_WhenPass1)
{
    const std::string INPUT{"1"};
    const std::string EXPECTED{"one"};

    evaluateTransform(INPUT, EXPECTED);
}

TEST_F(N2WTests, transform_ShouldRaiseException_WhenPass123a)
{
    const std::string INPUT{"123a"};

    ASSERT_THROW(n2w.transform(INPUT), std::invalid_argument);
}

/**
 * Tests for stoui function
 */
TEST_F(N2WTests, stoui_ShouldReturnParsed0_WhenPass0)
{
    const std::string INPUT{"0"};
    const uint32_t EXPECTED{0};

    int converted = n2w.stoui(INPUT);

    ASSERT_EQ(converted, EXPECTED);
}

TEST_F(N2WTests, stoui_ShouldReturnParsed1_WhenPass1)
{
    const std::string INPUT{"1"};
    const uint32_t EXPECTED{1};

    int converted = n2w.stoui(INPUT);

    ASSERT_EQ(converted, EXPECTED);
}

TEST_F(N2WTests, stoui_ShouldReturnParsed4294967295_WhenPass4294967295)
{
    const std::string INPUT{"4294967295"};
    const uint32_t EXPECTED{4294967295};

    uint32_t converted = n2w.stoui(INPUT);

    ASSERT_EQ(converted, EXPECTED);
}

TEST_F(N2WTests, stoui_ShouldRaiseException_WhenPass123a)
{
    const std::string INPUT{"123a"};

    ASSERT_THROW(n2w.stoui(INPUT), std::invalid_argument);
}

TEST_F(N2WTests, stoui_ShouldRaiseException_WhenPass1_234)
{
    const std::string INPUT{"1,234"};

    ASSERT_THROW(n2w.stoui(INPUT), std::invalid_argument);
}

TEST_F(N2WTests, stoui_ShouldRaiseException_WhenPass1_2_3)
{
    const std::string INPUT{"1,2,3"};

    ASSERT_THROW(n2w.stoui(INPUT), std::invalid_argument);
}

TEST_F(N2WTests, stoui_ShouldRaiseException_WhenPassNegative1)
{
    const std::string INPUT{"-1"};

    ASSERT_THROW(n2w.stoui(INPUT), std::invalid_argument);
}

TEST_F(N2WTests, stoui_ShouldRaiseException_WhenPass12345678901)
{
    const std::string INPUT{"12345678901"};

    ASSERT_THROW(n2w.stoui(INPUT), std::invalid_argument);
}

TEST_F(N2WTests, stoui_ShouldRaiseException_WhenPass4294967296)
{
    const std::string INPUT{"4294967296"};

    ASSERT_THROW(n2w.stoui(INPUT), std::invalid_argument);
}

TEST_F(N2WTests, stoui_ShouldRaiseException_WhenPass5678901234)
{
    const std::string INPUT{"5678901234"};

    ASSERT_THROW(n2w.stoui(INPUT), std::invalid_argument);
}

/**
 * Tests for isNumber function
 */

TEST_F(N2WTests, isNumber_ShouldReturnTrue_WhenPass0)
{
    const std::string INPUT{"0"};

    ASSERT_TRUE(n2w.isNumber(INPUT));
}

TEST_F(N2WTests, isNumber_ShouldReturnFalse_WhenPass123a)
{
    const std::string INPUT{"123a"};

    ASSERT_FALSE(n2w.isNumber(INPUT));
}

TEST_F(N2WTests, isNumber_ShouldReturnTrue_WhenPass1)
{
    const std::string INPUT{"1"};

    ASSERT_TRUE(n2w.isNumber(INPUT));
}

TEST_F(N2WTests, isNumber_ShouldReturnFalse_WhenPassNegative1)
{
    const std::string INPUT{"-1"};

    ASSERT_FALSE(n2w.isNumber(INPUT));
}

TEST_F(N2WTests, isNumber_ShouldReturnFalse_WhenPass1_234)
{
    const std::string INPUT{"1,234"};

    ASSERT_FALSE(n2w.isNumber(INPUT));
}

TEST_F(N2WTests, isNumber_ShouldReturnTrue_WhenPass999999999999)
{
    const std::string INPUT{"999999999999"};

    ASSERT_TRUE(n2w.isNumber(INPUT));
}

/**
 * Tests for isUnderLimit function
 */

TEST_F(N2WTests, isUnderLimit_ShouldReturnTrue_WhenPass0)
{
    const std::string INPUT{"0"};

    ASSERT_TRUE(n2w.isUnderLengthLimit(INPUT));
}

TEST_F(N2WTests, isUnderLimit_ShouldReturnFalse_WhenPass1000000000000)
{
    const std::string INPUT{"1000000000000"};

    ASSERT_FALSE(n2w.isUnderLengthLimit(INPUT));
}

TEST_F(N2WTests, isUnderLimit_ShouldReturnTrue_WhenPass999999999999)
{
    const std::string INPUT{"999999999999"};

    ASSERT_TRUE(n2w.isUnderLengthLimit(INPUT));
}

TEST_F(N2WTests, isUnderLimit_ShouldReturnTrue_WhenPass123a)
{
    const std::string INPUT{"123a"};

    ASSERT_TRUE(n2w.isUnderLengthLimit(INPUT));
}

TEST_F(N2WTests, isUnderLimit_ShouldReturnTrue_WhenPass1_234)
{
    const std::string INPUT{"1,234"};

    ASSERT_TRUE(n2w.isUnderLengthLimit(INPUT));
}

TEST_F(N2WTests, isUnderLimit_ShouldReturnFalse_WhenPass999_999_999_999)
{
    const std::string INPUT{"999,999,999,999"};

    ASSERT_FALSE(n2w.isUnderLengthLimit(INPUT));
}
