//
//  LookupKorean.hpp
//  NumberToWord
//
//  Created by Joohyung Ryu on 2023-11-14.
//

#ifndef LookupKorean_hpp
#define LookupKorean_hpp

#include <cmath>
#include <deque>
#include <iostream>
#include <sstream>
#include <vector>

#include "Lookup.hpp"

class LookupKorean : public Lookup
{
private:
    const uint8_t SEPARATOR_SIZE{4};
    const std::vector<std::string> ones{"영", "일", "이", "삼", "사", "오", "육", "칠", "팔", "구"};
    const std::vector<std::string> digits{"십", "백", "천"};
    std::deque<std::string> separatorWords{"만", "억"};

public:
    LookupKorean();
    virtual ~LookupKorean();

    virtual std::string getWordFrom(uint32_t number);
    virtual std::string getZeroWord();
    virtual std::string getSeparatorWord();
    virtual uint8_t getSeparatorSize();
};

#endif /* LookupKorean_hpp */
