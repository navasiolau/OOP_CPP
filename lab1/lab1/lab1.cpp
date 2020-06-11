#include <iostream>

using namespace std;

template<class T>
struct Node
{
    T data;
    Node* next;
};

template<class T>
class linkedList
{
private:
    Node<T> *head, * tail;
public:
    linkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void add_Node(T value) {
        try {
            Node<T> *tmp = new Node<T>;
            tmp->data = value;
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
        catch (int e) {
            cout << "Add Node error.\n";
            cin.clear();
            cin.ignore(256, '\n');
        }
    }

    void remove_Node() {
        Node<T> *elem;
        if (head != NULL)
        {
            elem = head;
            head = head->next;
            cout << "Delete element " << head->data << endl;
            delete elem;
        }
    }

    void search(T value) {
        Node<T> * ptr = head;
        while (ptr != NULL) {
            if (ptr->data == value) {
                cout << "\nElement by value: " << ptr->data << endl;
            }
            ptr = ptr->next;
        }
       
    }

    void display() {
        Node<T> *ptr;
        ptr = head;
        while (ptr != NULL) {
            cout << ptr->data << "\t";
            ptr = ptr->next;
        }
    }

    void ShellSort() {
        try {
            if (head)
            {
                int step = 0;
                int lenght = 0;
                Node<T> *p = head;
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
                            Node<T> *c = p;
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
            else {
                throw 1;
            }
        }
        catch (int e) {
            cout << "Linked list is empty. Nothing to sort\n";
            cin.clear();
            cin.ignore(256, '\n');
        }

        cout << "\nSorting is done!\n";
    }
};

void invalidInput(int e)
{
    cout << "Incorrect input value. Please input integer number\n";
    cin.clear();
    cin.ignore(256, '\n');
}

int main()
{
    int size = 0, tmpData, searchValue;
    linkedList<int> list;

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

    cout << "\nValue for search: ";
    cin >> searchValue;
    list.search(searchValue);

    return 0;
}
