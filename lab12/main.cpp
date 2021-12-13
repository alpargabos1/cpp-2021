#include <iostream>
#include "OrderedList.h"

int main() {
    OrderedList<int> list;
    list.insert(6);
    list.insert(5);
    list.insert(8);
    list.listItems();

    list.remove(6);
    list.listItems();
    return 0;
}