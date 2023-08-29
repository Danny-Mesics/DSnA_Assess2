

#include <iostream>
#include "DynamicArray.h"
#include "List.h"

int main()
{
    //Dynamic Array


    /*DynamicArray dArray;

    for (int i = 0; i < 10; i++) {
        dArray.PushBack(i);
    }
    for (int i = 0; i < 5; i++) {
        dArray.PopBack();
    }

    for (int i = 0; i < dArray.Size(); i++) {
        std::cout << dArray[i] << " " << std::endl;
    }

    for (int i = 0; i < 10; i++) {
        dArray.PushBack(i);
    }
    for (int i = 0; i < dArray.Size(); i++) {
        std::cout << dArray[i] << " ";
    }*/


    //LinkedList

    List integers;
    for (int i = 0; i < 10; i++) {
        integers.PushFront(i);
    }

    

    for (auto i = integers.Begin(); i != integers.End(); i++) {
        std::cout << *i << std::endl;
    }

    integers.Clear();
}
