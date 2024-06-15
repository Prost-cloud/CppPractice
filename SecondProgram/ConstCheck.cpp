#include <iostream>

struct ConstCheck
{
    static const int sz = 6;
};

int main()
{
    // const int ConstCheck::sz = 6; // does not compile
    const int chSZ = ConstCheck::sz * 4;

    std::cout << chSZ << std::endl;

    constexpr int arr[] = {1, 3, 4, 7, 9};
    std::cout << arr[1] << arr[2] << std::endl;
    // constexpr int *x = &arr[3]; // does not compile
    constexpr const int *x = &arr[3];

    return 0;
}