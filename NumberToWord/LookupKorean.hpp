//
//  LookupKorean.hpp
//  NumberToWord
//
//  Created by Joohyung Ryu on 2023-11-14.
//

#ifndef LookupKorean_hpp
#define LookupKorean_hpp

#include <iostream>

#include "Lookup.hpp"

class LookupKorean : public Lookup
{
private:
    const uint8_t SEPARATOR_SIZE{4};

public:
    LookupKorean();
    ~LookupKorean();

    virtual std::string getWord(uint32_t number);
    virtual std::string getZeroWord();
    virtual std::string getSeparatorWord();
    virtual uint8_t getSeparatorSize();
};

#endif /* LookupKorean_hpp */
