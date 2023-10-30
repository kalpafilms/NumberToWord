//
//  main.cpp
//  NumberToWord
//
//  Created by Joohyung Ryu on 2023-10-23.
//

#include <iostream>

#include "Number2Word.hpp"

int main(int argc, const char *argv[])
{
    Number2Word n2w;
    std::string number{};

    while (true) {
        std::cout << "Enter a number to convert, or 'q' to exit: ";
        std::cin >> number;
        
        // Exit when 'Q' is entered
        if (number.length() == 1 && std::toupper(number[0]) == 'Q') {
            break;
        }

        n2w.transform(number);
    }

    return 0;
}
