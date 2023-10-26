//
//  main.cpp
//  NumberToWord
//
//  Created by Joohyung Ryu on 2023-10-23.
//

#include <iostream>
#include <boost/algorithm/string.hpp>

int main(int argc, const char *argv[])
{
    std::string number{};
    std::cout << number << std::endl;
    while (boost::algorithm::to_upper_copy(number) != "Q")
    {
        std::cout << "Enter a number to convert, or 'q' to exit: ";
        std::cin >> number;
        std::cout << number << std::endl;
    }

    return 0;
}
