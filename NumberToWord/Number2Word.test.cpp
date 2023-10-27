//
//  Number2Word.test.cpp
//  N2WTests
//
//  Created by Joohyung Ryu on 2023-10-26.
//

#include <gtest/gtest.h>

#include "Number2Word.hpp"

class N2WTests : public ::testing::Test
{
protected:
    // Helper for evaluating the transform() function
    void evaluateTransform(const std::string &input, const std::string &expected)
    {
        testing::internal::CaptureStdout();
        n2w.transform(input);
        auto output = testing::internal::GetCapturedStdout();
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
    const auto INPUT = "0";
    const auto EXPECTED = "zero";

    evaluateTransform(INPUT, EXPECTED);
}

TEST_F(N2WTests, transform_ShouldPrintOutOne_WhenPass1)
{
    const auto INPUT = "1";
    const auto EXPECTED = "one";

    evaluateTransform(INPUT, EXPECTED);
}

TEST_F(N2WTests, transform_ShouldRaiseException_WhenPass123a)
{
    const auto INPUT = "123a";

    ASSERT_THROW(n2w.transform(INPUT), std::invalid_argument);
}

/**
 * Tests for stoui function
 */
TEST_F(N2WTests, stoui_ShouldReturnParsed0_WhenPass0)
{
    const auto INPUT = "0";
    const auto EXPECTED = 0;

    int converted = n2w.stoui(INPUT);

    ASSERT_EQ(converted, EXPECTED);
}

TEST_F(N2WTests, stoui_ShouldReturnParsed1_WhenPass1)
{
    const auto INPUT = "1";
    const auto EXPECTED = 1;

    int converted = n2w.stoui(INPUT);

    ASSERT_EQ(converted, EXPECTED);
}

TEST_F(N2WTests, stoui_ShouldReturnParsed4294967295_WhenPass4294967295)
{
    const auto INPUT = "4294967295";
    const auto EXPECTED = 4294967295;

    uint32_t converted = n2w.stoui(INPUT);

    ASSERT_EQ(converted, EXPECTED);
}

TEST_F(N2WTests, stoui_ShouldRaiseException_WhenPass123a)
{
    const auto INPUT = "123a";

    ASSERT_THROW(n2w.stoui(INPUT), std::invalid_argument);
}

TEST_F(N2WTests, stoui_ShouldRaiseException_WhenPass1_234)
{
    const auto INPUT = "1,234";

    ASSERT_THROW(n2w.stoui(INPUT), std::invalid_argument);
}

TEST_F(N2WTests, stoui_ShouldRaiseException_WhenPass1_2_3)
{
    const auto INPUT = "1,2,3";

    ASSERT_THROW(n2w.stoui(INPUT), std::invalid_argument);
}

TEST_F(N2WTests, stoui_ShouldRaiseException_WhenPassNegative1)
{
    const auto INPUT = "-1";

    ASSERT_THROW(n2w.stoui(INPUT), std::invalid_argument);
}

TEST_F(N2WTests, stoui_ShouldRaiseException_WhenPass12345678901)
{
    const auto INPUT = "12345678901";

    ASSERT_THROW(n2w.stoui(INPUT), std::invalid_argument);
}

TEST_F(N2WTests, stoui_ShouldRaiseException_WhenPass4294967296)
{
    const auto INPUT = "4294967296";

    ASSERT_THROW(n2w.stoui(INPUT), std::invalid_argument);
}

TEST_F(N2WTests, stoui_ShouldRaiseException_WhenPass5678901234)
{
    const auto INPUT = "5678901234";

    ASSERT_THROW(n2w.stoui(INPUT), std::invalid_argument);
}
