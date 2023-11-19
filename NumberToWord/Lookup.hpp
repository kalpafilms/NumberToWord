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

    /**
     * Forming a word per separator-sized length number (i.e., a number less than 1,000 for English. e.g., nine hundred ninety-nine for English)
     *
     * @param number Separator-sized length unsigned integer to get the English word
     * @return       An English word for the number
     */
    virtual std::string getWordFrom(uint32_t number) = 0;

    /**
     * Look up table for separator words
     *
     * @return A separator word (e.g., thousand for English)
     */
    virtual std::string getSeparatorWord() = 0;

    /**
     * Look up table for 0
     *
     * @return A word for the number 0 (e.g., zero for English)
     */
    virtual std::string getZeroWord() = 0;

    /**
     * Look up table for separators (e.g., 3 for English)
     *
     * @return A separator word
     */
    virtual uint8_t getSeparatorSize() = 0;
};

#endif /* Lookup_hpp */
