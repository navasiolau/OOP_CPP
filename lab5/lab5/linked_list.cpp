#include <iostream>
#include <functional>
#include "linked_list.h"

using namespace std;

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

// function to sort a singly linked list using insertion sort
template<class T>
void  LinkedList<T>::insertationSort(Node<T>** head_ref)
{
    // Initialize sorted linked list 
    Node<T>* sorted = NULL;

    // Traverse the given linked list and insert every 
    // node to sorted 
    Node<T>* current = *head_ref;
    while (current != NULL)
    {
        // Store next for next iteration 
        Node<T>* next = current->next;

        // insert current in sorted linked list 
        sortedInsert(&sorted, current);

        // Update current 
        current = next;
    }

    // Update head_ref to point to sorted linked list 
    *head_ref = sorted;
}

/* function to insert a new_node in a list. Note that this
  function expects a pointer to head_ref as this can modify the
  head of the input linked list (similar to push())*/
template<class T>
void LinkedList<T>::sortedInsert(Node<T>** head_ref, Node<T>* new_node)
{
    Node<T>* current;
    /* Special case for the head end */
    if (*head_ref == NULL || (*head_ref)->value >= new_node->value)
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else
    {
        /* Locate the node before the point of insertion */
        current = *head_ref;
        while (current->next != NULL &&
            current->next->value < new_node->value)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

template<class T>
void LinkedList<T>::findDiff(iterator start2) {
    auto i2 = start2;
    for (auto i1 = begin() ; i1 != NULL; i1++) {
        if (i1.nodePtr != i2.nodePtr) {
            cout << "First diff element:\t" << i2.nodePtr->value << ' ' << endl; 
            break;
        }
        i2++;
    }
}

template<class T>
void LinkedList<T>::setValues(iterator searchIt, T value) {
    auto i2 = searchIt;
    cout << "Desired value:\t\t" << i2.nodePtr->value << endl;
    cout << "Value for replace:\t" << value << endl;
    for (auto i1 = begin(); i1 != NULL; i1++) if (equalValue(&i1.nodePtr->value, &i2.nodePtr->value)) i1.nodePtr->value = value;
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