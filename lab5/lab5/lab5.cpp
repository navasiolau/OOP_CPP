#include <iostream>
#include "Product.cpp"
#include "linked_list.cpp"

int main()
{
    LinkedList<Product> stack, stack1, tmpStack;
    int arr1[6] = { 34, 3, 31, 98, 92, 23 };
    int count = 6;
    for (int i = 0; i < count; i++) {
        if (i < 2)
        {
            Product s("B", to_string(1), to_string(1), arr1[2]);
            stack.addNode(s);
        }
        else
        {
            Product s("A", to_string(i), to_string(-i), arr1[i]);
            stack.addNode(s);
        }
    }

    int arr2[6] = { 34, 3, 111, 98, 12, 23 };
    for (int i = 0; i < count; i++) {
        Product s("A", to_string(i), to_string(-i), arr2[i]);
        stack1.addNode(s);
    }


    cout << "Stack1:" << endl;
    stack.print();
    cout << "Stack2:" << endl;
    stack1.print();
    cout << "Sorted steck1: " << endl;
   /* stack.sort(Product::sortByCount());
    stack.print();*/
    stack.insertationSort(&stack.first);
    stack.print();
    cout << "\nSearch first diff element in stack1" << endl;
    stack.findDiff(stack1.begin(), Product::sortByCount());
    cout << "\t" << endl;
    Product forSearch("B", to_string(1), to_string(1), 31);
    tmpStack.addNode(forSearch);
    Product forReplace("C", to_string(1), to_string(4), 88);
    stack.setValues(tmpStack.begin(), forReplace);
    cout << "After replace: " << endl;
    stack.print();
    cout << "Pop: " << stack.popNode() << endl;
    cout << "Stack after pop:" << endl;
    stack.print();
    cout << "Print from 4rd: " << endl;
    stack.printFromStartToEnd(stack.at(3));

    return 0;
}
