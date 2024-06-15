#include <iostream>

template <typename T>
class VariableStorage
{
public:
    T *obj;
    VariableStorage(T *inValue)
    {
        obj = inValue;
    }
};

class Checker
{
public:
    int *data;
    Checker(int *inValue)
    {
        data = inValue;
        std::cout << "Ref ctor" << std::endl;
    }
    Checker(int inValue)
    {
        // std::cout << inValue << std::endl;
        // std::cout << &inValue << std::endl;
        data = new int(inValue);
        std::cout << "value ctor" << std::endl;
    }
    ~Checker()
    {
        std::cout << "Dector" << std::endl;
        delete data;
    }
};

std::ostream &operator<<(std::ostream &os, VariableStorage<Checker> &in);
std::ostream &operator<<(std::ostream &os, Checker *in);
std::ostream &operator<<(std::ostream &os, Checker &in);
void refCheck(int &a)
{
    std::cout << a;
}

int main()
{
    {
        Checker ccc(new int(13));
        std::cout << "c is ";
        std::cout << ccc << std::endl;
    }
    // VariableStorage v = VariableStorage(15);
    // VariableStorage b = VariableStorage('r');
    // VariableStorage r = VariableStorage("hello");
    // VariableStorage n = VariableStorage(5.5);
    // VariableStorage m = VariableStorage(true);
    char gg[] = "hello";
    std::cout << gg << std::endl;
    int p = 999;
    int *q = &p;
    Checker *c = new Checker(new int(12321));
    Checker *a = new Checker(123);
    // VariableStorage cc = new VariableStorage(c);
    VariableStorage cc(c);
    VariableStorage aa(a);

    // std::cout << v.obj << std::endl;
    // std::cout << b.obj << std::endl;
    // std::cout << r.obj << std::endl;
    // std::cout << n.obj << std::endl;
    // std::cout << m.obj << std::endl;
    std::cout << cc << std::endl;
    std::cout << cc.obj << std::endl;
    std::cout << aa << std::endl;
    std::cout << aa.obj << std::endl;
    // int a = 102030;
    // int &b = a;
    // refCheck(b);
    std::cout << *q << std::endl;

    return 0;
}

std::ostream &operator<<(std::ostream &os, VariableStorage<Checker> &in)
{
    std::cout << "Here pls" << std::endl;
    os << in.obj;
    return os;
}

std::ostream &operator<<(std::ostream &os, Checker *in)
{
    std::cout << "Here pls Checker POINTER" << std::endl;
    os << *in->data;
    return os;
}

std::ostream &operator<<(std::ostream &os, Checker &in)
{
    std::cout << "Here pls Checker value" << std::endl;
    os << in.data;
    return os;
}