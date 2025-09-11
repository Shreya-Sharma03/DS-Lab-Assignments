/* Write a program for the evaluation of a Postfix expression */
#include <iostream>
using namespace std;

int main()
{
    char exp[100];
    int stack[100];
    int top = -1;
    cin >> exp;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        char c = exp[i];

        if (c >= '0' && c <= '9')
        {
            stack[++top] = c - '0';
        }
        else
        {
            int b = stack[top--];
            int a = stack[top--];

            if (c == '+')
                stack[++top] = a + b;
            else if (c == '-')
                stack[++top] = a - b;
            else if (c == '*')
                stack[++top] = a * b;
            else if (c == '/')
                stack[++top] = a / b;
        }
    }
    cout << stack[top];
    return 0;
}
