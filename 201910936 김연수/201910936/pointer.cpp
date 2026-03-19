#include "pointer.hpp"

#include <iostream>
#include <string>

auto pointer() -> void
{
    //int pointedInt = 100;
    //int* pointerInt = &pointedInt;

    //std::cout << "Pointed : " << *pointerInt << "\tAddress : " << &pointerInt;
    //
    //char pointedChar[3][10] = { "Dreams", "Come", "True!" };
    //const char* pointerChar[3] = { {"Dreams"}, {"Come"}, {"True!"} };

    //char* cacheChar[4] = {};

    //for (auto i = 0; i < 4; i++)
    //{
    //    char cache{};
    //    std::cout << "#" << i+1 << "\t: ";
    //    std::cin >> cache;
    //    cacheChar[i] = &cache;
    //    std::cout << "\n";
    //}

    //std::string inputString = {};
    //std::cout << "Enter String : ";
    //std::cin >> inputString;

    //std::cout << "\nString Size : "  << inputString.size();

    int array[2][3][4]{};

    int maximum = 2 * 3 * 4;

    int current = 1;
    for (auto& first : array)
    {
        for (auto& second : first)
        {
            for (auto& third : second)
            {
                std::cout << "Enter Input (" << current++ << "/" <<  maximum << ")\t: ";
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