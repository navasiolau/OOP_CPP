#include <iostream>
#include "Product.cpp"
#include "linked_list.cpp"

int main()
{
    LinkedList<Product> stack, stack1;
    int arr1[6] = { 34, 3, 31, 98, 92, 23 };
    int count = 6;
    for (int i = 0; i < count; i++) {
        Product s("A", to_string(i), to_string(-i), arr1[i]);
        stack.addNode(s);
    }

    int arr2[6] = { 34, 3, 111, 98, 12, 23 };
    for (int i = 0; i < count; i++) {
        Product s("A", to_string(i), to_string(-i), arr2[i]);
        stack1.addNode(s);
    }
    cout << "Stack:" << endl;
    stack.print();
    /*cout << "Pop: " << stack.popNode() << endl;
    cout << "Stack:" << endl;
    stack.print();
    cout << "Print from 4rd: " << endl;
    stack.printFromStartToEnd(stack.at(3));*/
    cout << "Sorted: " << endl;
    //stack.sort(Product::sortByCount());
    //stack.print();
    stack.insertationSort(Product::sortByCount());
    stack.print();
    stack.findDiff(stack, stack1);
    //cout << "Print from 3rd: " << endl;
    //stack.printFromStartToEnd(stack.at(2));
    return 0;
}
