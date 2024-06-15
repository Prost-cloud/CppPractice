#include <map>
#include <iostream>

template <typename K, typename V>
class interval_map
{
    friend void IntervalMapTest();
    V m_valBegin;
    std::map<K, V> m_map;

public:
    // constructor associates whole range of K with val
    interval_map(V const &val)
        : m_valBegin(val)
    {
    }

    // Assign value val to interval [keyBegin, keyEnd).
    // Overwrite previous values in this interval.
    // Conforming to the C++ Standard Library conventions, the interval
    // includes keyBegin, but excludes keyEnd.
    // If !( keyBegin < keyEnd ), this designates an empty interval,
    // and assign must do nothing.
    /*Присвойте значение val интервалу [keyBegin, keyEnd).
        Перезапишите предыдущие значения в этом интервале.
        В соответствии с соглашениями стандартной библиотеки C++ интервал
        включает keyBegin, но исключает keyEnd.
        Если !( keyBegin < keyEnd ), это обозначает пустой интервал,
        и Assign не должен ничего делать.*/
    void assign(K const &keyBegin, K const &keyEnd, V const &val)
    {
        /* here */
        K it = keyBegin;
        while (it < keyEnd)
        {
            m_map[it] = val;
            it++;
        }
    }

    // look-up of the value associated with key
    V const &operator[](K const &key) const
    {
        auto it = m_map.upper_bound(key);
        if (it == m_map.begin())
        {
            return m_valBegin;
        }
        else
        {
            return (--it)->second;
        }
    }
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.

int main()
{
    std::cout << "Test!" << std::endl;
    interval_map im<int, char>(1, 'f');
}