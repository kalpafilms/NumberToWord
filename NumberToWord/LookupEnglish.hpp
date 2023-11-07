//
//  LookupEnglish.hpp
//  NumberToWord
//
//  Created by Joohyung Ryu on 2023-10-29.
//

#ifndef LookupEnglish_hpp
#define LookupEnglish_hpp

#include <deque>
#include <iostream>
#include <sstream>
#include <vector>

class LookupEnglish
{
private:
    const uint8_t SEPARATOR_SIZE{3};

    const std::vector<std::string> onesDigit{
        "zero",
        "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
        "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    const std::vector<std::string> tensDigit{"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    const std::string HUNDRED{"hundred"};
    std::deque<std::string> thousandDigits{"thousand", "million", "billion"};

public:
    LookupEnglish();
    virtual ~LookupEnglish();

    std::string getWord(uint32_t number);
    std::string getWordUnderSeparator(uint32_t number);
    std::string getSeparatorWord();
    uint8_t getSeparatorSize();
};
#endif /* LookupEnglish_hpp */
