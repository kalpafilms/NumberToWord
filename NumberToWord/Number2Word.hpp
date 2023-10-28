//
//  Number2Word.hpp
//  NumberToWord
//
//  Created by Joohyung Ryu on 2023-10-26.
//

#ifndef Number2Word_hpp
#define Number2Word_hpp

#include <iostream>

class Number2Word
{
public:
    Number2Word();
    virtual ~Number2Word();

    void transform(const std::string &input);
    uint32_t stoui(const std::string &input);
    bool isUnderLimit(const std::string &input);
    bool isNumber(const std::string &input);
};

#endif /* Number2Word_hpp */
