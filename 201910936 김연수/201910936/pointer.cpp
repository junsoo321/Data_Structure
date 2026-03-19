#include "pointer.hpp"

#include <iostream>
#include <string>

auto pointer() -> void
{
    std::cout << "Exercise Week 3\n"
        << "Enter Exercise Number : ";
    
    auto key = -1;
    std::cin >> key;

    auto hasKey = [&key]() -> const bool
        {
            return (key >= 1 && key <= 5);
        };

    while (!hasKey())
    {
        std::cout << "Wrong Key! Enter Again : ";
        std::cin >> key;
    }

    switch (key)
    {
    case 1:
    {
        int pointedInt = 100;
        int* pointerInt = &pointedInt;

        std::cout << "Pointed : " << *pointerInt << "\tAddress : " << &pointerInt;
    }
        break;
    case 2:
    {
        char pointedChar[3][10] = { "Dreams", "Come", "True!" };
        const char* pointerChar[3] = { {"Dreams"}, {"Come"}, {"True!"} };

        char* cacheChar[4] = {};

        for (auto i = 0; i < 4; i++)
        {
            char cache{};
            std::cout << "#" << i + 1 << "\t: ";
            std::cin >> cache;
            cacheChar[i] = &cache;
            std::cout << "\n";
        }
    }
        break;

    case 3:
    {
        std::string inputString = {};
        std::cout << "Enter String : ";
        std::cin >> inputString;

        std::cout << "\nString Size : " << inputString.size();

        char cacheChar = {};
        char* inputChar = &cacheChar;

    }
        break;

    case 4:
    {
        int array[2][3][4]{};

        int current = 1;
        int maximum = 2 * 3 * 4;

        for (auto& first : array)
        {
            for (auto& second : first)
            {
                for (auto& third : second)
                {
                    std::cout << "Enter Input (" << current++ << "/" << maximum << ")\t: ";
                    std::cin >> third;
                }
            }
        }

        int x_in = 0;
        for (auto& x : array)
        {
            int y_in = 0;
            for (auto& y : x)
            {
                int z_in = 0;
                for (auto& z : y)
                {
                    std::cout << "array[" << x_in << "][" << y_in << "][" << z_in << "]\t: " << z << "\n";
                    z_in++;
                }
                y_in++;
            }
            x_in++;
        }
    }
    break;
    case 5:
    {
        std::string inputArray[2][3]{};

        int x_in = 1;
        for (auto& x : inputArray)
        {
            int y_in = 1;
            for (auto& y : x)
            {
                auto printIndex = [&y_in]() -> const std::string
                    {
                        switch (y_in)
                        {
                        case 1: return "name";
                        case 2: return "major";
                        case 3: return "id";
                        }
                    };

                std::cout << "Student #" << x_in << "'s " << printIndex() << "\t: ";
                std::cin >> y;
                y_in++;
            }
            x_in++;
        }

        x_in = 1;
        for (auto& x : inputArray)
        {
            int y_in = 1;
            for (auto& y : x)
            {
                auto printIndex = [&y_in]() -> const std::string
                    {
                        switch (y_in)
                        {
                        case 1: return "name";
                        case 2: return "major";
                        case 3: return "id";
                        }
                    };

                std::cout << "Student #" << x_in << "'s " << printIndex() << "\t: " << y << "\n";
                y_in++;
            }
            x_in++;
        }
    }
    break;

    default:
        std::cout << "Wrong Key Number";
        break;

    }

    
}