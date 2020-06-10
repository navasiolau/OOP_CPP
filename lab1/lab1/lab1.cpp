#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

class linkedList
{
private:
    Node* head, * tail;
public:
    linkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void add_Node(int n);
    void remove_Node();
    void display();
    void ShellSort();
};

void linkedList::add_Node(int n)
{
    Node* tmp = new Node;
    tmp->data = n;
    tmp->next = NULL;

    if (head == NULL)
    {
        head = tmp;
        tail = tmp;
    }
    else
    {
        tail->next = tmp;
        tail = tail->next;
    }
}

void linkedList::remove_Node()
{
    Node* elem;
    if (head != NULL)
    {
        elem = head;
        head = head->next;
        cout << "Delete element " << head->data << endl;
        delete elem;
    }
}

void linkedList::display() {
    Node* ptr;
    ptr = head;
    while (ptr != NULL) {
        cout << ptr->data << "\t";
        ptr = ptr->next;
    }
}

void linkedList::ShellSort()
{
    if (head)
    {
        int step = 0;
        int lenght = 0;
        Node* p = head;
        while (p)
        {
            lenght++;
            p = p->next;
        }
        while (2 * (3 * step + 1) <= lenght)
            step = 3 * step + 1;
        for (step; step > 0; step /= 3)
            for (int i = step; i > 0; i--)
                for (int j = step - i; j < lenght; j += step)
                {
                    p = head;
                    int k;
                    for (k = 0; k < j; k++)
                        p = p->next;
                    Node* c = p;
                    int temp = k + step;
                    while (c)
                    {
                        for (k; k < temp;)
                            if (c)
                            {
                                k++;
                                c = c->next;
                            }
                            else break;
                        if (c)
                            if (p->data > c->data)
                            {
                                int t = p->data;
                                p->data = c->data;
                                c->data = t;
                            }
                        temp += step;
                    }
                }
    }
    cout << "\nSorting is done!\n";
}

void invalidInput(int e)
{
    cout << "Incorrect input value. Please input integer number\n";
    cin.clear();
    cin.ignore(256, '\n');
}

void main()
{
    int size = 0, tmpData;
    linkedList list;

    while (size == 0)
    {
        try {
            cout << "Enter the size of the list, please: ";
            cin >> size;
            if (size <= 0) throw 1;
        }
        catch (int e) {
            invalidInput(e);
        }
    }

    for (int i = 1; i <= size; i++) {
        cout << "Input element " << i << ": ";
        try {
            cin >> tmpData;
            if (cin.fail()) throw 2;
            list.add_Node(tmpData);
        }
        catch (int e) {
            invalidInput(e);
            i--;
        }
    }

    cout << "The linked list is: \n";
    list.display();
    list.ShellSort();
    list.display();
}
