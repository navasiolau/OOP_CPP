#include <iostream>
#include <functional>
#include "linked_list.h"

using namespace std;

//template<class T>
//Node<T>::Node(T value, Node<T>* next) {
//    this->value = value;
//    this->next = next;
//}

template<class T>
LinkedList<T>::LinkedList() {
    Node<T>* first = NULL;
    Node<T>* last = NULL;
    size = 0;
}

template<class T>
void LinkedList<T>::addNode(T value) {
    Node<T>* node = new Node<T>;
    node->value = value;
    node->next = NULL;

    if (size > 0) {
        last->next = node;
        last = last->next;
    }
    else {
        first = node;
        last = node;
    }
    size++;
}

template<class T>
T LinkedList<T>::popNode() {
    if (size > 0) {
        T value = first->value;
        first = first->next;
        size--;
        if (size == 0) {
            last = NULL;
        }
        return value;
    }
    throw length_error("List is empty");
}

template<class T>
bool LinkedList<T>::contains(T value) {
    Node<T>* current = first;
    for (int i = 0; i < size; i++) {
        if (current->value == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

//template<class T>
//void LinkedList<T>::sort(function<bool(T, T)> comparator) {
//    bool swapped;
//    Node<T>* current;
//    int lastSortedIndex = size - 1;
//    do {
//        swapped = false;
//        current = first;
//        for (int i = 0; i < lastSortedIndex; i++) {
//            if (comparator(current->value, current->next->value)) {
//                T temp = current->value;
//                current->value = current->next->value;
//                current->next->value = temp;
//                swapped = true;
//            }
//            current = current->next;
//        }
//        lastSortedIndex--;
//    } while (swapped);
//}

template<class T>
void LinkedList<T>::insertationSort(function<bool(T, T)> comparator) {
    LinkedList<T> tmpStack;

    while (this->size != 0) {
        Node<T>* tmp = this->first;
        this->popNode();

        while (tmpStack.size != 0 && comparator(tmpStack.first->value, tmp->value))
        {
            this->addNode(tmpStack.first->value);
            tmpStack.popNode();
        }
        this->print();
        cout << "\n";
        tmpStack.addNode(tmp->value);
    }

    *this = tmpStack;
}

template<class T>
void LinkedList<T>::findDiff(iterator start2, function<bool(T, T)> comparator) {
    auto i2 = start2;
    for (auto i1 = begin() ; i1 != NULL; i1++) {
        if (i1.nodePtr != i2.nodePtr) {
            cout << "First diff element: " << i2.nodePtr->value << ' ' << endl; 
            break;
        }
        i2++;
    }
}

template<class T>
void LinkedList<T>::setValues(iterator searchIt, T value) {
    auto i2 = searchIt;
    cout << "SearchIt->value: " << i2.nodePtr->value << endl;
    cout << "Value - " << value << endl;
    for (auto i1 = begin(); i1 != NULL; i1++) {
        if (equalValue(&i1.nodePtr->value, &i2.nodePtr->value)) {
            cout << "in if state: " << i2.nodePtr->value << endl;
            //cout << "Element for search: " << i2.nodePtr->value << ' ' << endl;
            //cout << "Element for replace: " << i1.nodePtr->value << ' ' << endl;
            i1.nodePtr->value = value;
        }
    }
}

template<class T>
LinkedList<T> LinkedList<T>::filter(function<bool(T)> predicate) {
    LinkedList<T> newList;
    Node<T>* current = first;
    for (int i = 0; i < size; i++) {
        if (predicate(current->value)) {
            newList.addFirst(current->value);
        }
        current = current->next;
    }
    return newList;
}

template<class T>
void LinkedList<T>::print() const {
    printFromStartToEnd(begin());
}

template<class T>
void LinkedList<T>::swap(T* a, T* b) {
    T t = *a;
    *a = *b;
    *b = t;
}

template<class T>
bool LinkedList<T>::equalValue(T *a, T *b) {
    if (*a == *b)
    {
        return true;
    }
    return false;
}

template<class T>
void LinkedList<T>::printFromStartToEnd(iterator start) const {
    for (auto i = start; i != NULL; i++) {
        cout << i.nodePtr->value << ' ' << endl;
    }
}