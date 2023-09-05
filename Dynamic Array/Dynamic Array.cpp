

#include <iostream>
#include "DynamicArray.h"
#include "List.h"

int main()
{
    //LinkedList

    List integers;

    integers.PushBack(14);
    integers.PushBack(24);
    integers.PushBack(34);
    integers.PushBack(44);
    integers.Remove(34);

    std::cout << integers.Count() << std::endl;
    

    for (auto i = integers.Begin(); i != integers.End(); i++) {
        std::cout << *i << std::endl;
        if (*i == 14) {
            integers.Insert(i, 50);
        }
    }

    integers.Clear();
}
