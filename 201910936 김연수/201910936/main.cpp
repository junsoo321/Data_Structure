#include <iostream>

auto main() -> int
{
    int num = 0;
    float fnum = 1.0;

    num = 100;
    num = -30;

    fnum = 123.456;

    std::cout << "num : " << num << std::endl;
    std::cout << "fnum: " << fnum << std::endl;

    return 0;
}