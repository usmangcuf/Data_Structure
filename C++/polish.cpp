
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define MAX 100

// Stack implementation using array
class Stack
{
private:
    char arr[MAX];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == MAX - 1;
    }

    void push(char value)
    {
        if (isFull())
        {
            cout << "Stack Overflow!" << endl;
            return;
        }

        arr[++top] = value;
    }

    char pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow!" << endl;
            return '\0';
        }

        return arr[top--];
    }

    char peek()
    {
        if (isEmpty())
            return '\0';

        return arr[top];
    }
};

// Check whether character is an operator
bool isOperator(char ch)
{
    return ch == '+' || ch == '-' ||
           ch == '*' || ch == '/' ||
           ch == '^';
}

// Return operator precedence
int precedence(char ch)
{
    if (ch == '^')
        return 3;

    if (ch == '*' || ch == '/')
        return 2;

    if (ch == '+' || ch == '-')
        return 1;

    return 0;
}

// Convert infix to prefix
string infixToPrefix(string infix)
{
    string reversed = infix;

    // Step 1: Reverse infix expression
    reverse(reversed.begin(), reversed.end());

    // Step 2: Exchange brackets
    for (int i = 0; i < reversed.length(); i++)
    {
        if (reversed[i] == '(')
            reversed[i] = ')';

        else if (reversed[i] == ')')
            reversed[i] = '(';
    }

    Stack s;

    string postfix = "";

    // Step 3: Convert reversed expression to postfix
    for (int i = 0; i < reversed.length(); i++)
    {
        char ch = reversed[i];

        // Operand
        if (ch >= '0' && ch <= '9')
        {
            postfix += ch;
        }

        // Opening bracket
        else if (ch == '(')
        {
            s.push(ch);
        }

        // Closing bracket
        else if (ch == ')')
        {
            while (!s.isEmpty() && s.peek() != '(')
            {
                postfix += s.pop();
            }

            if (!s.isEmpty())
                s.pop();
        }

        // Operator
        else if (isOperator(ch))
        {
            while (!s.isEmpty() &&
                   s.peek() != '(' &&
                   (precedence(s.peek()) > precedence(ch) ||
                    (precedence(s.peek()) == precedence(ch) &&
                     ch == '^')))
            {
                postfix += s.pop();
            }

            s.push(ch);
        }
    }

    // Step 4: Pop remaining operators
    while (!s.isEmpty())
    {
        postfix += s.pop();
    }

    // Step 5: Reverse postfix to obtain prefix
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

int main()
{
    string infix;

    cout << "Enter Infix Expression: ";
    cin >> infix;

    string prefix = infixToPrefix(infix);

    cout << "Infix Expression: "
         << infix << endl;

    cout << "Prefix Expression: "
         << prefix << endl;

    return 0;
}
