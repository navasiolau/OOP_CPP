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

template<class T>
void LinkedList<T>::sort(function<bool(T, T)> comparator) {
    bool swapped;
    Node<T>* current;
    int lastSortedIndex = size - 1;
    do {
        swapped = false;
        current = first;
        for (int i = 0; i < lastSortedIndex; i++) {
            if (comparator(current->value, current->next->value)) {
                T temp = current->value;
                current->value = current->next->value;
                current->next->value = temp;
                swapped = true;
            }
            current = current->next;
        }
        lastSortedIndex--;
    } while (swapped);
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

//template<class T>
//void LinkedList<T>::quickSort(function<bool(T, T)> comparator) {
//    _quickSort(first, last, comparator);
//}
//
//template<class T>
//void LinkedList<T>::_quickSort(Node<T>* l, Node<T>* h, function<bool(T, T)> comparator) {
//    if (h != NULL && l != h && l != h->next) {
//        Node<T>* p = partition(l, h, comparator);
//        _quickSort(l, p->previous, comparator);
//        _quickSort(p->next, h, comparator);
//    }
//}
//
//template<class T>
//Node<T>* LinkedList<T>::partition(Node<T>* l, Node<T>* h, function<bool(T, T)> comparator) {
//    T x = h->value;
//    Node<T>* i = l->previous;
//    for (Node<T>* j = l; j != h; j = j->next) {
//        if (comparator(x, j->value)) {
//            i = (i == NULL) ? l : i->next;
//            swap(&(i->value), &(j->value));
//        }
//    }
//    i = (i == NULL) ? l : i->next;
//    swap(&(i->value), &(h->value));
//    return i;
//}

template<class T>
void LinkedList<T>::swap(T* a, T* b) {
    T t = *a;
    *a = *b;
    *b = t;
}

template<class T>
void LinkedList<T>::printFromStartToEnd(iterator start) const {
    for (auto i = start; i != NULL; i++) {
        cout << i.nodePtr->value << ' ' << endl;
    }
}