//
//  LookupEnglish.hpp
//  NumberToWord
//
//  Created by Joohyung Ryu on 2023-10-29.
//

#ifndef LookupEnglish_hpp
#define LookupEnglish_hpp

#include <iostream>
#include <deque>
#include <vector>

class LookupEnglish
{
private:
    std::vector<std::string> onesDigit;
    std::vector<std::string> tensDigit;
    std::deque<std::string> thousandDigits;

public:
    LookupEnglish();
    virtual ~LookupEnglish();

    std::string getWord(uint32_t number);
    std::string getThousandSeparator();
};
#endif /* LookupEnglish_hpp */
