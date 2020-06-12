#include <iostream>
#include "Product.cpp"
#include "linked_list.cpp"

int main()
{
    LinkedList<Product> stack;
    int count = 7;
    for (int i = 0; i < count; i++) {
        Product s("A", to_string(i), to_string(-i), rand());
        stack.addNode(s);
    }
    cout << "Stack:" << endl;
    stack.print();
    cout << "Pop: " << stack.popNode() << endl;
    cout << "Stack:" << endl;
    stack.print();
    cout << "Print from start to end: " << endl;
    stack.printFromStartToEnd(stack.at(1));
    stack.quickSort(Product::sortByName());
    cout << "Sorted: " << endl;
    stack.print();
    //cout << "Print from 3rd: " << endl;
    //stack.printFromStartToEnd(stack.at(2));
    return 0;
}
