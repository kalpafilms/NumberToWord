//
//  main.cpp
//  NumberToWord
//
//  Created by Joohyung Ryu on 2023-10-23.
//

#include <iostream>

int main(int argc, const char *argv[])
{
    std::string number;

    std::cout << "Enter a number to convert, or 'q' to exit: ";
    std::cin >> number;
    std::cout << std::endl;

    std::cout << number << std::endl;

    return 0;
}
