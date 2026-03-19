#include "pointer.hpp"

#include <iostream>
#include <string>

constexpr int WEEK3_START   = 1;
constexpr int WEEK3_END     = 7;

// forward declare
auto factorial(int val) -> int;

auto pointer() -> void
{
    std::cout 
        << "Exercise Week 3\n\n"

        << "============================\n"
        << "#1 : Integer Pointer\n"
        << "#2 : Char Pointer\n"
        << "#3 : String Size\n"
        << "#4 : Multi-Dimensional Array\n"
        << "#5 : Student Array\n"
        << "#6 : Struct Definition\n"
        << "#7 : Factorial Function\n"
        << "============================\n\n"

        << "Enter Exercise Number : ";
    
    int key = -1;
    std::cin >> key;

    auto hasKey = [&key]() -> const bool
        {
            return (key >= WEEK3_START && key <= WEEK3_END);
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
                        case 3: return "student id";
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
                        case 3: return "student id";
                        }
                    };

                std::cout << "Student #" << x_in << "'s " << printIndex() << "\t: " << y << "\n";
                y_in++;
            }
            x_in++;
        }
    }
    break;

    case 6:
    {
        struct employee {
            char name[10];
            int year;
            int pay;
        };

        struct employee slave {"poor-guy", 100, 2000000 };
    }
    break;

    case 7:
    {
        int value{};
        std::cout << "Enter Input : ";
        std::cin >> value;

        auto result = factorial(value);

        std::cout << "Factorial " << value << " : " << result << "\n";
    }

    break;

    default:
        std::cout << "Wrong Key Number";
        break;

    }

    
}

auto factorial(int val) -> int
{
    std::cout << "Factorial(" << val << ") Called !\n";
    if (val == 1)
    {
        return val;
    }
    else
    {
        return val * factorial(val-1);
    }
}