#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *link;
    node(int val)
    {
        data = val;
        link = NULL;
    }
    node()
    {
        data = 0;
        link = NULL;
    }
} *first = NULL;
void addnode(node *&head, int val)
{
    node *temp = new node(val);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        node *ptr = head;
        while (ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = temp;
    }
}
void deletenode(node *&head, int val)
{
    node *temp = head;
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    if (head->data == val)
    {
        head = head->link;
        delete temp;
        return;
    }
    while (temp->link != NULL && temp->link->data != val)
    {
        temp = temp->link;
    }
    if (temp->link == NULL)
    {
        cout << "Value not found in the list" << endl;
        return;
    }
    node *delNode = temp->link;
    temp->link = delNode->link;
    delete delNode;
}
void display(node *head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->link;
    }
    cout << endl;
}
int main()
{
    char choice;
    int value;
    do
    {

        cout << "1. Add a node\n";
        cout << "2. Delete a node\n";
        cout << "3. Display the list\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case '1':
            cout << "Enter the value to add: ";
            cin >> value;
            addnode(first, value);
            break;
        case '2':
            cout << "Enter the value to delete: ";
            cin >> value;
            deletenode(first, value);
            break;
        case '3':
            display(first);
            break;
        case '4':
            exit(0);
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != '4');
}