
#include <iostream>
using namespace std;

const int MAX = 5;

class Stack
{
private:
    int arr[MAX];
    int TOP;

public:

    // Constructor
    Stack()
    {
        TOP = -1;
    }

    // Check whether stack is empty
    bool isEmpty()
    {
        return TOP == -1;
    }

    // Check whether stack is full
    bool isFull()
    {
        return TOP == MAX - 1;
    }

    // PUSH operation
    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack Overflow! "
                 << "Cannot insert " << value << endl;
            return;
        }

        TOP++;
        arr[TOP] = value;

        cout << value << " inserted successfully.\n";
    }

    // POP operation
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow! "
                 << "Stack is Empty.\n";
            return;
        }

        int value = arr[TOP];

        TOP--;

        cout << "Removed element: "
             << value << endl;
    }

    // PEEK operation
    void peek()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty.\n";
            return;
        }

        cout << "Top Element: "
             << arr[TOP] << endl;
    }

    // MULTIPUSH operation
    void multipush(int n)
    {
        int value;

        for (int i = 0; i < n; i++)
        {
            if (isFull())
            {
                cout << "Stack Full! "
                     << "Cannot insert more elements.\n";
                break;
            }

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
            if (isEmpty())
            {
                cout << "Stack Empty! "
                     << "Cannot remove more elements.\n";
                break;
            }

            pop();
        }
    }

    // DISPLAY operation
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty.\n";
            return;
        }

        cout << "\nStack Elements:\n";
        cout << "----------------\n";

        for (int i = TOP; i >= 0; i--)
        {
            cout << arr[i];

            if (i == TOP)
                cout << "  <-- TOP";

            cout << endl;
        }

        cout << "----------------\n";
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
        cout << "\n===== STACK USING ARRAY =====\n";
        cout << "1. PUSH\n";
        cout << "2. POP\n";
        cout << "3. PEEK\n";
        cout << "4. MULTIPUSH\n";
        cout << "5. MULTIPOP\n";
        cout << "6. DISPLAY\n";
        cout << "7. CHECK EMPTY\n";
        cout << "8. CHECK FULL\n";
        cout << "0. EXIT\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.peek();
                break;

            case 4:
                cout << "How many elements? ";
                cin >> n;

                if (n < 0)
                    cout << "Invalid number of elements.\n";
                else
                    s.multipush(n);

                break;

            case 5:
                cout << "How many elements to remove? ";
                cin >> n;

                if (n < 0)
                    cout << "Invalid number of elements.\n";
                else
                    s.multipop(n);

                break;

            case 6:
                s.display();
                break;

            case 7:
                if (s.isEmpty())
                    cout << "Stack is Empty.\n";
                else
                    cout << "Stack is Not Empty.\n";
                break;

            case 8:
                if (s.isFull())
                    cout << "Stack is Full.\n";
                else
                    cout << "Stack is Not Full.\n";
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
