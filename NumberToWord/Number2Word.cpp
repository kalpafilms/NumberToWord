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
 * 
 * @return      A converted word of the input number
 */
std::string Number2Word::transform(const std::string &input)
{
    // Throw exception when the input is not valid.
    bool isExceedLengthLimit = !isUnderLengthLimit(input);
    if (isExceedLengthLimit)
    {
        throw std::invalid_argument("Exceed length limit");
    }
    bool notNumber = !isNumber(input);
    if (notNumber)
    {
        throw std::invalid_argument("Not a number");
    }

    std::deque<std::string> converted;
    std::stringstream output;
    LookupEnglish lookup;
    const uint32_t separatorUnit{(uint32_t)std::pow(10, lookup.getSeparatorSize())};
    uint32_t number{stoui(input)};

    if (number == 0)
    {
        output << lookup.getZeroWord();
    }

    while (number > 0)
    {
        uint32_t remainder{number % separatorUnit};
        number /= separatorUnit;
        converted.push_front(lookup.getWordFrom(remainder));
        if (number > 0)
        {
            converted.push_front(lookup.getSeparatorWord());
        }
    }

    for (int i = 0; i < converted.size(); i++)
    {
        if (i > 0)
        {
            output << " ";
        }
        output << converted[i];
    }

    return output.str();
}

/**
 * String to unsigned integer
 *
 * @param input String to convert integer
 * @return      Converted integer
 */
uint32_t Number2Word::stoui(const std::string &input)
{
    uint32_t converted{0};
    const uint32_t MAX_CHECKER{UINT32_MAX / 10};

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

/**
 * Verify that a string is shorter than the specific length
 *
 * @param input String to validate
 * @return      Whether it is shorter than the limit
 */
bool Number2Word::isUnderLengthLimit(const std::string &input)
{
    const size_t LENGTH_LIMIT{12};

    bool isShorterThanLimit = input.length() <= LENGTH_LIMIT;
    return isShorterThanLimit;
}

/**
 * Verify that a string consists only of numbers
 *
 * @param input String to validate
 * @return      Whether all characters are numeric
 */
bool Number2Word::isNumber(const std::string &input)
{
    for (const auto c : input)
    {
        bool notNumber = (c < '0' || c > '9');
        if (notNumber)
        {
            return false;
        }
    }

    return true;
}
