//
//  LookupEnglish.cpp
//  NumberToWord
//
//  Created by Joohyung Ryu on 2023-10-29.
//

#include "LookupEnglish.hpp"

LookupEnglish::LookupEnglish() {}
LookupEnglish::~LookupEnglish() {}

/**
 * Forming a word for three-digit number
 */
std::string LookupEnglish::getWord(uint32_t number)
{
    std::stringstream word;

    uint32_t hundred{number / 100};
    uint32_t tens{number % 100};

    if (hundred > 0)
    {
        word << getWordUnderSeparator(hundred) << " " << HUNDRED;
    }

    if (tens > 0)
    {
        if (word.str().size() > 0)
        {
            word << " ";
        }

        word << getWordUnderSeparator(tens);
    }

    return word.str();
}

/**
 * Look up table for one or two-digit number
 *
 * @param number Less than two-digit unsigned integer to get the English word
 * @return       An English word for the number
 */
std::string LookupEnglish::getWordUnderSeparator(uint32_t number)
{
    if (number > 99)
    {
        throw std::invalid_argument("The number must be less than 100");
    }

    std::string word;

    if (number < onesDigit.size())
    {
        word = onesDigit[number];
    }
    else
    {
        int tens = number / 10;
        int ones = number % 10;

        word = tensDigit[tens - 2];

        if (ones != 0)
        {
            word.append("-").append(onesDigit[ones]);
        }
    }

    return word;
}

/**
 * Look up table for thousand separators
 *
 * @return A thousand separator word
 */
std::string LookupEnglish::getSeparatorWord()
{
    if (thousandDigits.empty())
    {
        throw std::out_of_range("No more thousand separator");
    }

    std::string separator{thousandDigits.front()};
    thousandDigits.pop_front();

    return separator;
}

/**
 * Separator size, numbers are divided by 3 digits in English (e.g. 1,000 or 9,999,999)
 *
 * @return The separator size, 3
 */
uint8_t LookupEnglish::getSeparatorSize()
{
    return SEPARATOR_SIZE;
}
