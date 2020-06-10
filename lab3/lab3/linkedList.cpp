#include <iostream>
#include <functional>

using namespace std;

template<class T>
struct Node {

    T value;

    Node* next;
};

template<class T>
struct linkedList {

    Node<T>* first = NULL;
    Node<T>* last = NULL;

    int size = 0;

    void add(T value) {
        Node<T> *node = new Node<T>;
        node->value = value;
        node->next = NULL;

        if (size > 0)
        {
            last->next = node;
            last = last->next;
        }
        else
        {
            first = node;
            last = node;
        }
        size++;
    }

    T pop() {
        if (size > 1) {
            T value = last->value;
            last = last->next;
            first->previous = last;
            last->next = first;
            size--;
            return value;
        }
        else if (size == 1) {
            T value = first->value;
            first = NULL;
            last = NULL;
            size--;
            return value;
        }
        throw length_error("List is empty");
    }

    bool contains(T value) {
        Node<T>* current = first;
        for (int i = 0; i < size; i++) {
            if (current->value == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void sort(function<bool(T, T)> comparator) {
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

    linkedList<T> filter(function<bool(T)> predicate) {
        linkedList<T> newList;
        Node<T>* current = first;
        for (int i = 0; i < size; i++) {
            if (predicate(current->value)) {
                newList.add(current->value);
            }
            current = current->next;
        }
        return newList;
    }

    void print() const {
        Node<T>* current = first;
        while (current != NULL) {
            cout << current->value << ' ' << endl;
            current = current->next;
        }
    }
};