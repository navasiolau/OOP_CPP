#include <functional>

#ifndef INC_5_LINKED_LIST_H
#define INC_5_LINKED_LIST_H

template<class T>
struct Node {

    T value;

    Node* next;
};

template<class T>
struct LinkedList {

    Node<T>* first;
    Node<T>* last;

    int size;

    LinkedList<T>();

    void addNode(T value);

    T popNode();

    bool contains(T value);

    //void sort(std::function<bool(T, T)> comparator);

    void insertationSort(std::function<bool(T, T)> comparator);

    LinkedList<T> filter(std::function<bool(T)> predicate);

    void print() const;

    //void quickSort(std::function<bool(T, T)> comparator);

    //void _quickSort(Node<T>* l, Node<T>* h, std::function<bool(T, T)> comparator);

    //Node<T>* partition(Node<T>* l, Node<T>* h, std::function<bool(T, T)> comparator);

    void swap(T* a, T* b);
    bool equalValue(T* a, T* b);

    struct iterator {
        friend class LinkedList;

        Node<T>* nodePtr;

        iterator(Node<T>* newPtr) : nodePtr(newPtr) {}

        iterator() : nodePtr(nullptr) {}

        bool operator!=(const iterator& itr) const {
            return nodePtr != itr.nodePtr;
        }

        bool operator==(const iterator& itr) const {
            return nodePtr == itr.nodePtr;
        }

        T& operator*() const {
            return nodePtr->next->data;
        }

        iterator operator++(int) {
            iterator temp = *this;
            nodePtr = nodePtr->next;
            return temp;
        }
    };

    iterator begin() const {
        return iterator(first);
    }

    iterator end() const {
        return iterator(last);
    }

    iterator at(int index) const {
        auto b = begin();
        auto e = end();
        int position = 0;
        for (auto i = b; i != e; i++) {
            if (position == index) {
                return i;
            }
            position++;
        }
        return b;
    }

    void printFromStartToEnd(iterator start) const;
    void findDiff(iterator start2, std::function<bool(T, T)> comparator);
    void setValues(iterator searchIt, T value);
    //void printFromEndToStart(iterator end) const;
};

#endif //INC_5_LINKED_LIST_H