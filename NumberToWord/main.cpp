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
    std::string converted{};

    while (true)
    {
        std::cout << "Enter a number to convert, or 'q' to exit: ";
        std::cin >> number;

        // Exit when 'Q' is entered
        if (number.length() == 1 && std::toupper(number[0]) == 'Q')
        {
            break;
        }

        try
        {
            converted = n2w.transform(number);
            std::cout << converted << std::endl;
        }
        catch (std::invalid_argument const &e)
        {
            std::cout << "Invalid argument (" << number << "): " << e.what() << std::endl;
        }
    }

    return 0;
}
