//
// Created by Alpar on 12/13/2021.
//

#ifndef MAIN_CPP_ORDEREDLIST_H
#define MAIN_CPP_ORDEREDLIST_H

#include <iostream>
#include <functional>

using namespace std;

template<class T, class LessComp = less<T>, class Equal = equal_to<T> >

class OrderedList {
private:
    struct Node {
        T value;
        Node *next;

        Node(T value = T(), Node *next = nullptr) : value(value), next(next) {}

    };

    Node *first = nullptr;
    int numElements = 0;
public:
    OrderedList() {
        numElements = 0;
        first = nullptr;
    }

    virtual ~OrderedList() = default;

    bool isEmpty();

    void insert(T);

    void remove(T);

    int size();

    bool find(T &);

    void listItems(ostream & = cout);

};

template<class T, class LessComp, class Equal>
bool OrderedList<T, LessComp, Equal>::isEmpty() {
    return false;
}

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::insert(T v) {
    Node *temp = new Node(v);
    ++this->numElements;
    if (first == nullptr || !LessComp()(first->value, v)) {
        temp->next = first;
        first = temp;
        return;
    }
    Node *act = first;
    while (act->next != NULL && LessComp()(act->next->value, v)) {

        act = act->next;
    }
    temp->next = act->next;
    act->next = temp;
}

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::remove(T v) {
    Node *prev = nullptr, *act = first;

    while (act && !Equal()(act->value, v)) {
        prev = act;
        act = act->next;
    }

    if (!act) {
        return;
    }

    if (prev) {
        prev->next = act->next;
    } else {
        first = first->next;
    }

    delete act;
}

template<class T, class LessComp, class Equal>
int OrderedList<T, LessComp, Equal>::size() {
    return 0;
}

template<class T, class LessComp, class Equal>
bool OrderedList<T, LessComp, Equal>::find(T &) {
    return false;
}

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::listItems(ostream &) {
    Node *temp = first;
    while (temp != nullptr) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

#endif //MAIN_CPP_ORDEREDLIST_H
