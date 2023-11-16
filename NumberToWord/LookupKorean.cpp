//
//  LookupKorean.cpp
//  NumberToWord
//
//  Created by Joohyung Ryu on 2023-11-14.
//

#include "LookupKorean.hpp"

LookupKorean::LookupKorean() {}
LookupKorean::~LookupKorean() {}

/**
 * Forming a word per separator-sized length number (e.g., 구천팔백칠십육 for 9876)
 *
 * @param number Separator-sized length unsigned integer to get the English word
 * @return       A Korean word for the number
 */
std::string LookupKorean::getWord(uint32_t number)
{
    return std::string();
}

/**
 * Look up table for separators
 *
 * @return A separator word per ten thousand
 */
std::string LookupKorean::getSeparatorWord()
{
    if (separatorWords.empty())
    {
        throw std::out_of_range("No more separator");
    }

    std::string separator{separatorWords.front()};
    separatorWords.pop_front();
    
    return separator;
}

/**
 * Look up table for 0
 *
 * @return A word for the number 0, 영
 */
std::string LookupKorean::getZeroWord()
{
    return "영";
}

/**
 * Separator size, numbers are divided by 4 digits in Korean (e.g. 일만/10000 or 구억 구천구백구십구만 구천구백구십구/999999999)
 *
 * @return The separator size, 4
 */
uint8_t LookupKorean::getSeparatorSize()
{
    return SEPARATOR_SIZE;
}
