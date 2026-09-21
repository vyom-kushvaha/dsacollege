#include <iostream>
#include <cmath>
#include <cctype>
using namespace std;

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value)
{
    stack[++top] = value;
}

int pop()
{
    return stack[top--];
}

int main()
{
    string postfix;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    for (char ch : postfix)
    {
        if (isdigit(ch))
        {
            push(ch - '0');
        }
        else
        {
            int operand2 = pop();
            int operand1 = pop();

            switch (ch)
            {
                case '+':
                    push(operand1 + operand2);
                    break;

                case '-':
                    push(operand1 - operand2);
                    break;

                case '*':
                    push(operand1 * operand2);
                    break;

                case '/':
                    push(operand1 / operand2);
                    break;

                case '^':
                    push(pow(operand1, operand2));
                    break;
            }
        }
    }

    cout << "Result: " << pop() << endl;

    return 0;
}