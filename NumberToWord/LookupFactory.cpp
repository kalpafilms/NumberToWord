//
//  LookupFactory.cpp
//  NumberToWord
//
//  Created by Joohyung Ryu on 2023-11-21.
//

#include "LookupFactory.hpp"

LookupFactory::LookupFactory() {}

LookupFactory::~LookupFactory()
{
    if (lookup)
    {
        delete lookup;
    }
}

Lookup *LookupFactory::getLookupTableFor(const Language target)
{
    if (target == Language::ENGLISH)
    {
        lookup = new LookupEnglish();
    }
    else if (target == Language::KOREAN)
    {
        lookup = new LookupKorean();
    }

    return lookup;
}
