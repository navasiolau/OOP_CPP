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

    void insertationSort(Node<T>** head_ref);
    void sortedInsert(Node<T>** head_ref, Node<T>* new_node);

    LinkedList<T> filter(std::function<bool(T)> predicate);

    void print() const;

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
    void findDiff(iterator start2);
    void setValues(iterator searchIt, T value);
};

#endif //INC_5_LINKED_LIST_H