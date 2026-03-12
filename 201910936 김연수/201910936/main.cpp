#include <iostream>

auto main() -> int
{
    int val1 = 15;

    val1--;
    val1++;

    int val2 = -15;

    float fnum = 1.0;
    fnum = 123.456;

    std::cout << "val1 : " << val1 << std::endl;
    std::cout << "val2 : " << val2 << std::endl;
    std::cout << "fnum: " << fnum << std::endl;

    return 0;
}