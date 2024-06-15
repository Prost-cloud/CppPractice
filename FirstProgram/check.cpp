#include <iostream>

void Chapter1();
void Chapter2();
void Chapter3();
void Chapter4();
int sum(int *a, int *b);
int sum(int a, int b);

int main()
{
    int aa = 0;
    // Chapter1();
    std::setlocale(0, "");
    std::cout << "привет" << std::endl;
    Chapter2();
    // Chapter3();
    // Chapter4();
    std::cin >> aa;
    return 0;
}

void Chapter3()
{
    int a = 0;
    for (;;)
    {
        int *intPtrArray = new int[1000];
        int *intPtr = new int;
        *intPtr = a;
        a++;
        std::cout << *intPtr;
        delete[] intPtrArray;
        delete intPtr;
    }
}

void Chapter2()
{
    int a, b;
    std::cout << "Enter a, b" << std::endl;
    std::cin >> a >> b;
    std::cout << "Sum is " << sum(a, b) << std::endl;
    std::cout << "a, b in main ";
    std::cout << a << " " << b << std::endl;
    std::cout << "Sum is " << sum(&a, &b) << std::endl;
    std::cout << "a, b in main ";
    std::cout << a << " " << b << std::endl;
}

#if FALSE
int sum(int &a, int &b)
{
    a++;
    b++;
    std::cout << "a, b in func ";
    std::cout << a << " " << b << std::endl;
    return a + b;
}
#endif

int sum(int a, int b)
{
    a++;
    b++;
    std::cout << "a, b in func ";
    std::cout << a << " " << b << std::endl;
    return a + b;
}

int sum(int *a, int *b)
{
    a++;
    b++;
    std::cout << "a, b in func ";
    std::cout << a << " " << b << std::endl;
    return *a + *b;
}

void Chapter1()
{
    int b, d;
    int *a = &b;
    int &c = d;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;
    std::cout << "Hello, world!" << std::endl;
    std::cin >> b;
    std::cin >> d;

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;

    std::cout << "Hello, world!" << std::endl;
    std::cin >> *a;
    std::cin >> c;

    std::cout << a << std::endl;
    std::cout << &a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;

    std::cout << "Hello, world!" << std::endl;
    return;
}
