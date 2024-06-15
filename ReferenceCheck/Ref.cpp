#include <iostream>

class MySumm
{
public:
    int *a;
    MySumm(int v)
    {
        std::cout << "create\n";
        a = new int(v);
    }
    ~MySumm()
    {
        delete a;
        std::cout << "DeCreate\n";
    }
};

int summ(int &a, int &b)
{
    return a + b;
};

int summ(MySumm a, MySumm b)
{
    return *a.a + *b.a;
};

int main()
{
    int a = 5, b = 9;
    int cc = 50, dd = 100;
    int *c = &cc, *d = &dd;

    MySumm *ms = new MySumm(13);
    MySumm *ms2 = new MySumm(17);

    std::cout << summ(a, b) << std::endl;
    std::cout << summ(*c, *d) << std::endl;
    std::cout << summ(*ms, *ms2) << std::endl;

    std::cout << (ms->a) << std::endl;
    std::cout << (ms2->a) << std::endl;

    return 0;
};