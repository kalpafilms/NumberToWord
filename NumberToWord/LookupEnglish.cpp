//
//  LookupEnglish.cpp
//  NumberToWord
//
//  Created by Joohyung Ryu on 2023-10-29.
//

#include "LookupEnglish.hpp"

LookupEnglish::LookupEnglish()
{
    onesDigit = {
        "zero",
        "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
        "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    tensDigit = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
}
LookupEnglish::~LookupEnglish() {}

/**
 * Look up word for two-digit number
 *
 * @param number Two-digit unsigned integer to get the English word
 * @return       An English word for the number
 */
std::string LookupEnglish::getWord(uint32_t number)
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