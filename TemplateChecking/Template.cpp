#include <iostream>

template <typename T>
concept Addable = requires(T a, T b) {
    a + b;
    a - b;
};

class MyClass
{
public:
    int a;
    MyClass(int v)
    {
        a = v;
    }

    int GetValue() const
    {
        return a;
    }

    MyClass operator+(MyClass r)
    {
        return a + r.a;
    }
};

MyClass operator-(MyClass l, MyClass r)
{
    return l.a - r.a;
}

template <Addable T>
T summ(T first, T second)
{
    return first + second + 1;
};

template <>
char summ<char>(char first, char second)
{
    std::cout << "in overload\n";
    return first + second;
};

template <typename T>
void print(T data)
{
    std::cout << data << '\n';
}

template <typename T, typename... Ts>
void print(T arg, Ts... args)
{
    std::cout << arg << '\n';
    print(args...);
}

int main()
{
    std::cout << summ(1, 2) << '\n'
              << summ(3.5, 7.4) << '\n'
              << summ(3.5f, 9.f) << "\n\n";
    //   << summ('a', 7);

    print(1, 't', 3);
    // MyClass a(5), b(7);
    // std::cout << std::max(a, b).GetValue() << "\n";
    // std::cout << summ(a, b).GetValue();
    return 0;
}