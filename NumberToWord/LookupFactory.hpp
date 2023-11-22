//
//  LookupFactory.hpp
//  NumberToWord
//
//  Created by Joohyung Ryu on 2023-11-21.
//

#ifndef LookupFactory_hpp
#define LookupFactory_hpp

#include "Language.hpp"
#include "Lookup.hpp"
#include "LookupEnglish.hpp"
#include "LookupKorean.hpp"

/**
 * Simple factory for Lookup classes
 */
class LookupFactory
{
private:
    Lookup *lookup{nullptr};

public:
    LookupFactory();
    virtual ~LookupFactory();

    Lookup *getLookupTableFor(const Language target);
};

#endif /* LookupFactory_hpp */
