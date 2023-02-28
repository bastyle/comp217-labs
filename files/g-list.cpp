// Iterators - Insertion and Removal
// iterator_list.cpp

#include <list>
#include <iostream>

int main()
{
    std::list<double> prices;  // initially empty

    prices.push_back(10.43);   // add 10.43
    prices.push_back(20.54);   // add 20.54
     // data here 12.52
    prices.push_back(32.43);   // add 32.43

    prices.insert(--prices.end(), 12.52);
    prices.erase(++prices.begin());

    for (auto it = prices.begin(); it != prices.end(); it++)
        std::cout << *it << "  ";
    std::cout << std::endl;
}