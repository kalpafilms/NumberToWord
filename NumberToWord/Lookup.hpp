//
//  LookupByLanguage.hpp
//  NumberToWord
//
//  Created by Joohyung Ryu on 2023-11-13.
//

#ifndef Lookup_hpp
#define Lookup_hpp

#include <iostream>

class Lookup
{
public:
    virtual ~Lookup(){};

    virtual std::string getWord(uint32_t number) = 0;
    virtual std::string getWordUnderSeparator(uint32_t number) = 0;
    virtual std::string getSeparatorWord() = 0;
    virtual uint8_t getSeparatorSize();
};

#endif /* Lookup_hpp */
