#include <iostream>
//#include <conio.h>
using namespace std;
/////////////////////////////////////////////////////////////
//////////////// Node Creation //////////////////////////////
struct node
{
    int data;
    node *front;
    node *rear;
} *first = NULL;
void addnode(int a)
{
    node *next, *temp;

    if (first == NULL)
    {
        // First node
        first = new node;
        first->data = a;
        first->front = NULL;
        first->rear = NULL;
    }
    else
    {
        // Traverse to the last node
        next = first;

        while (next->rear != NULL)
            next = next->rear;

        // Create a new node
        temp = new node;
        temp->data = a;
        temp->rear = NULL;
        temp->front = next;

        // Connect the previous last node
        next->rear = temp;
    }
}


/////////////////////////////////////////////////////////////////
/////////////////////////Node Deletion////////////////////////////// 
void del(void)
{
    int i;

    cout << "Enter the value to delete: ";
    cin >> i;

    node *next = first;

    // Check whether the list is empty
    if (first == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    // Search for the value
    while (next != NULL && next->data != i)
        next = next->rear;

    // Value not found
    if (next == NULL)
    {
        cout << "No such data\n";
        return;
    }

    // Deleting the first node
    if (next == first)
    {
        first = first->rear;

        if (first != NULL)
            first->front = NULL;
    }
    else
    {
        // Connect the previous node to the next node
        next->front->rear = next->rear;

        // If next is not the last node
        if (next->rear != NULL)
            next->rear->front = next->front;
    }

    delete next;
    cout << "Node deleted successfully\n";
}
///////////////////////////////////////////////////////////////////////
////////////////////////////Link List Linear Traversal/////////////////
void show(void)
{
    node *next = first;

    if (first == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    while (next != NULL)
    {
        cout << next->data << endl;
        next = next->rear;
    }
}
int main()
{
    int i, ch;

    do
    {
        cout << "\n1. Add Node\n";
        cout << "2. Show List\n";
        cout << "3. Delete Node\n";
        cout << "4. Quit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
            case 1:
                cout << "Enter integer value: ";
                cin >> i;
                addnode(i);
                break;

            case 2:
                show();
                break;

            case 3:
                del();
                break;

            case 4:
                cout << "Program terminated.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (ch != 4);

    return 0;
}