//
//  Number2Word.cpp
//  NumberToWord
//
//  Created by Joohyung Ryu on 2023-10-26.
//

#include "Number2Word.hpp"

Number2Word::Number2Word() {}

Number2Word::~Number2Word() {}

/**
 * Transform an integer to a word
 *
 * @param input User input string to be converted into a word
 */
void Number2Word::transform(const std::string &input)
{
    if (input == "1")
    {
        std::cout << "one";
    }
    else if (input == "0")
    {
        std::cout << "zero";
    }
    else
    {
        throw std::invalid_argument("Not a number");
    }
}

/**
 * String to unsigned integer
 *
 * @param input String to convert integer
 * @return      Converted integer
 */
uint32_t Number2Word::stoui(const std::string &input)
{
    uint32_t converted = 0;
    const uint32_t MAX_CHECKER = UINT32_MAX / 10;

    bool isLongerThanMaxLength = (input.length() > 10);
    if (isLongerThanMaxLength)
    {
        throw std::invalid_argument("Exceeding the maximum length");
    }

    for (const auto c : input)
    {
        bool notNumber = (c < '0' || c > '9');
        if (notNumber)
        {
            throw std::invalid_argument("Not a number");
        }
        bool isGreaterThanMax = (converted > MAX_CHECKER || (converted == MAX_CHECKER && c > '5'));
        if (isGreaterThanMax)
        {
            throw std::invalid_argument("Greater than the maximum unsigned integer");
        }

        converted *= 10;
        converted += c - '0';
    }

    return converted;
}