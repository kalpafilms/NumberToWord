//
//  main.cpp
//  NumberToWord
//
//  Created by Joohyung Ryu on 2023-10-23.
//

#include <iostream>

#include "Language.hpp"
#include "Number2Word.hpp"

int main(int argc, const char *argv[])
{
    Number2Word n2w;
    Language language{Language::NONE};
    std::string input{};
    std::string converted{};

    while (true)
    {
        std::cout << "To convert a number to a word: Select a language, or '0' to exit" << std::endl
                  << "1. English" << std::endl
                  << "2. Korean" << std::endl
                  << "> ";
        std::getline(std::cin, input);

        if (input.length() > 1 || input.empty())
        {
            continue;
        }

        switch (input[0] - 48)
        {
            case 0:
                return 0;
            case 1:
                language = Language::ENGLISH;
                break;
            case 2:
                language = Language::KOREAN;
                break;
            default:
                break;
        }

        if (language != Language::NONE)
        {
            std::cout << std::endl;
            break;
        }
    }

    if (language == Language::KOREAN)
    {
        // To temporarily ignore the unused variable warning
    }

    while (true)
    {
        std::cout << "Enter a number to convert, or 'q' to exit: ";
        std::getline(std::cin, input);

        if (input.empty())
        {
            continue;
        }

        // Exit when 'Q' is entered
        if (input.length() == 1 && std::toupper(input[0]) == 'Q')
        {
            break;
        }

        try
        {
            converted = n2w.transform(input);
            std::cout << converted << std::endl;
        }
        catch (std::invalid_argument const &e)
        {
            std::cout << "Invalid argument (" << input << "): " << e.what() << std::endl;
        }
    }

    return 0;
}
