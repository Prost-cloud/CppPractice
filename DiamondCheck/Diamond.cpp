#include <iostream>

struct Animal
{
    virtual ~Animal() = default;
    virtual void Eat()
    {
        std::cout << "Eated\n";
    }
};
 
struct Mammal : virtual Animal
{
    virtual void Breathe()
    {
        std::cout << "Breathed\n";
    }

    virtual void Eat()
    {
        std::cout << "M Eated\n";
    }
};

struct WingedAnimal : virtual Animal
{
    virtual void Flap()
    {
        std::cout << "Flapped\n";
    }

    virtual void Eat()
    {
        std::cout << "W Eated\n";
    }
};
 
struct Bat : Mammal, WingedAnimal
{
    virtual void Eat()
    {
        std::cout << "B Eated\n";
    }
};

int main()
{
    Mammal a;
    WingedAnimal b;
    Bat c;

    a.Eat();
    b.Eat();
    c.Eat();
    c.Breathe();
    c.Flap();

    return 0;
}