#include <bits/stdc++.h>
using namespace std;

int main()
{
    char stack[100];
    int top = -1;
    string exp;
    cout << "Enter an expression: ";
    cin >> exp;
    bool balanced = true;
    for (int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            stack[++top] = ch;
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (top == -1)
            {
                balanced = false;
                break;
            }
            char open = stack[top--];
            if ((ch == ')' && open != '(') || (ch == '}' && open != '{') || (ch == ']' && open != '['))
            {
                balanced = false;
                break;
            }
        }
    }
    if (top != -1)
    {
        balanced = false;
    }
    if (balanced)
        cout << "Expression is Balanced\n";
    else
        cout << "Expression is Not Balanced\n";
    return 0;
}