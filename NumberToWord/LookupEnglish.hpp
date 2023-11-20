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

#include "Lookup.hpp"

class LookupEnglish : public Lookup
{
private:
    const uint8_t SEPARATOR_SIZE{3};
    const std::vector<std::string> ones{
        "zero",
        "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
        "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    const std::vector<std::string> tens{"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    const std::string HUNDRED{"hundred"};
    std::deque<std::string> separatorWords{"thousand", "million", "billion"};

public:
    LookupEnglish();
    virtual ~LookupEnglish();

    virtual std::string getWordFrom(uint32_t number);
    virtual std::string getZeroWord();
    virtual std::string getSeparatorWord();
    virtual uint8_t getSeparatorSize();

    std::string getWordUnderSeparator(uint32_t number);
};
#endif /* LookupEnglish_hpp */
