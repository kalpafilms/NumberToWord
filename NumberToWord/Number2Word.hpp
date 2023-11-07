//
//  Number2Word.hpp
//  NumberToWord
//
//  Created by Joohyung Ryu on 2023-10-26.
//

#ifndef Number2Word_hpp
#define Number2Word_hpp

#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>

#include "LookupEnglish.hpp"

class Number2Word
{
public:
    Number2Word();
    virtual ~Number2Word();

    void transform(const std::string &input);
    uint32_t stoui(const std::string &input);
    bool isUnderLengthLimit(const std::string &input);
    bool isNumber(const std::string &input);
};

#endif /* Number2Word_hpp */
