#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int evaluatePostfix(string postfix)
{
    stack<int> s;

    for (char ch : postfix)
    {
        // Operand
        if (isdigit(ch))
        {
            s.push(ch - '0');
        }

        // Operator
        else
        {
            int operand2 = s.top();
            s.pop();

            int operand1 = s.top();
            s.pop();

            int result;

            switch (ch)
            {
                case '+':
                    result = operand1 + operand2;
                    break;

                case '-':
                    result = operand1 - operand2;
                    break;

                case '*':
                    result = operand1 * operand2;
                    break;

                case '/':
                    result = operand1 / operand2;
                    break;

                case '^':
                    result = pow(operand1, operand2);
                    break;
            }

            s.push(result);
        }
    }

    return s.top();
}

int main()
{
    string postfix;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    cout << "Result: "
         << evaluatePostfix(postfix) << endl;

    return 0;
}
