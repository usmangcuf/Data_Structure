
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#define MAX 100

// Stack implementation using array
class Stack
{
private:
    double arr[MAX];
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

    void push(double value)
    {
        if (isFull())
        {
            cout << "Stack Overflow!" << endl;
            return;
        }

        arr[++top] = value;
    }

    double pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow!" << endl;
            return 0;
        }

        return arr[top--];
    }

    double peek()
    {
        if (isEmpty())
            return 0;

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

// Perform mathematical operation
double calculate(double a, double b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;

    case '-':
        return a - b;

    case '*':
        return a * b;

    case '/':
        if (b == 0)
        {
            cout << "Error: Division by zero!" << endl;
            return 0;
        }
        return a / b;

    case '^':
        return pow(a, b);

    default:
        return 0;
    }
}

// Evaluate prefix expression
double evaluatePrefix(string prefix)
{
    Stack s;

    // Scan expression from right to left
    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        char ch = prefix[i];

        // If operand, push onto stack
        if (ch >= '0' && ch <= '9')
        {
            s.push(ch - '0');
        }

        // If operator, perform calculation
        else if (isOperator(ch))
        {
            double a = s.pop();

            double b = s.pop();

            double result = calculate(a, b, ch);

            s.push(result);
        }
    }

    // Final answer
    return s.pop();
}

int main()
{
    string prefix;

    cout << "Enter Prefix Expression: ";
    cin >> prefix;

    double result = evaluatePrefix(prefix);

    cout << "Prefix Expression: "
         << prefix << endl;

    cout << "Evaluation Result: "
         << result << endl;

    return 0;
}
