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

    cout << list.size() << endl;

    if (list.find(5)) {
        cout << "True\n";
    } else {
        cout << "False\n";
    }

    return 0;
}