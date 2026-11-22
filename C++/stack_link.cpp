
#include <iostream>
#include <new>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node* next;
};

class Stack
{
private:

    Node* TOP;
    bool initialized;

public:

    // Constructor
    Stack()
    {
        TOP = NULL;
        initialized = false;
    }

    // Initialize linked list
    void initialize()
    {
        if (initialized)
        {
            cout << "Linked List Already Created.\n";
            return;
        }

        TOP = NULL;
        initialized = true;

        cout << "Linked List Created Successfully.\n";
    }

    // Check whether stack is empty
    bool isEmpty()
    {
        return TOP == NULL;
    }

    // PUSH operation
    void push(int value)
    {
        // Automatically initialize if not created
        if (!initialized)
        {
            initialized = true;
            TOP = NULL;
        }

        // Create a new node
        Node* newNode = new(nothrow) Node;

        if (newNode == NULL)
        {
            cout << "Memory Allocation Failed!\n";
            return;
        }

        newNode->data = value;

        // Connect new node with existing TOP
        newNode->next = TOP;

        // Update TOP
        TOP = newNode;

        cout << value << " inserted successfully.\n";
    }

    // POP operation
    void pop()
    {
        // Check whether linked list was created
        if (!initialized)
        {
            cout << "No Linked List Created!\n";
            return;
        }

        // Check whether linked list is empty
        if (isEmpty())
        {
            cout << "Linked List is Empty!\n";
            return;
        }

        // Temporary pointer
        Node* temp = TOP;

        int value = temp->data;

        // Move TOP to next node
        TOP = TOP->next;

        // Delete previous TOP node
        delete temp;

        cout << "Removed element: "
             << value << endl;
    }

    // PEEK operation
    void peek()
    {
        if (!initialized)
        {
            cout << "No Linked List Created!\n";
            return;
        }

        if (isEmpty())
        {
            cout << "Linked List is Empty!\n";
            return;
        }

        cout << "Top Element: "
             << TOP->data << endl;
    }

    // MULTIPUSH operation
    void multipush(int n)
    {
        int value;

        for (int i = 0; i < n; i++)
        {
            cout << "Enter value " << i + 1 << ": ";
            cin >> value;

            push(value);
        }
    }

    // MULTIPOP operation
    void multipop(int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (!initialized)
            {
                cout << "No Linked List Created!\n";
                break;
            }

            if (isEmpty())
            {
                cout << "Linked List is Empty!\n";
                break;
            }

            pop();
        }
    }

    // DISPLAY operation
    void display()
    {
        if (!initialized)
        {
            cout << "No Linked List Created!\n";
            return;
        }

        if (isEmpty())
        {
            cout << "Linked List is Empty!\n";
            return;
        }

        Node* temp = TOP;

        cout << "\nStack Elements:\n";
        cout << "----------------------\n";

        while (temp != NULL)
        {
            cout << temp->data;

            if (temp == TOP)
                cout << "  <-- TOP";

            cout << endl;

            temp = temp->next;
        }

        cout << "----------------------\n";
    }

    // Destructor: release all allocated memory
    ~Stack()
    {
        Node* temp;

        while (TOP != NULL)
        {
            temp = TOP;
            TOP = TOP->next;

            delete temp;
        }
    }
};

// MAIN FUNCTION
int main()
{
    Stack s;

    int choice;
    int value;
    int n;

    do
    {
        cout << "\n===== STACK USING LINKED LIST =====\n";

        cout << "1. CREATE LINKED LIST\n";
        cout << "2. PUSH\n";
        cout << "3. POP\n";
        cout << "4. PEEK\n";
        cout << "5. MULTIPUSH\n";
        cout << "6. MULTIPOP\n";
        cout << "7. DISPLAY\n";
        cout << "8. CHECK EMPTY\n";
        cout << "0. EXIT\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                s.initialize();
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;

                s.push(value);
                break;

            case 3:
                s.pop();
                break;

            case 4:
                s.peek();
                break;

            case 5:
                cout << "How many elements? ";
                cin >> n;

                if (n < 0)
                    cout << "Invalid number of elements.\n";
                else
                    s.multipush(n);

                break;

            case 6:
                cout << "How many elements to remove? ";
                cin >> n;

                if (n < 0)
                    cout << "Invalid number of elements.\n";
                else
                    s.multipop(n);

                break;

            case 7:
                s.display();
                break;

            case 8:
                if (s.isEmpty())
                    cout << "Stack is Empty.\n";
                else
                    cout << "Stack is Not Empty.\n";
                break;

            case 0:
                cout << "Program Terminated.\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 0);

    return 0;
}
