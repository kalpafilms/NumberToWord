//
//  main.cpp
//  NumberToWord
//
//  Created by Joohyung Ryu on 2023-10-23.
//

#include <iostream>
#include <boost/algorithm/string.hpp>

#include "Number2Word.hpp"

int main(int argc, const char *argv[])
{
    Number2Word n2w;
    std::string number{};

    while (boost::algorithm::to_upper_copy(number) != "Q")
    {
        std::cout << "Enter a number to convert, or 'q' to exit: ";
        std::cin >> number;
        n2w.transform(number);
    }

    return 0;
}
