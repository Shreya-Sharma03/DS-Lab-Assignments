/* Write a program to convert an Infix expression into a Postfix expression. */
#include <iostream>
using namespace std;

char s[100];
int t = -1;

int p(char o)
{
    if (o == '*' || o == '/')
        return 2;
    if (o == '+' || o == '-')
        return 1;
    return 0;
}

int main()
{
    char in[100], out[100];
    int i = 0, j = 0;
    cin >> in;
    while (in[i])
    {
        char c = in[i];
        if (isalpha(c))
            out[j++] = c;
        else
        {
            while (t >= 0 && p(s[t]) >= p(c))
                out[j++] = s[t--];
            s[++t] = c;
        }
        i++;
    }
    while (t >= 0)
        out[j++] = s[t--];
    out[j] = '\0';
    cout << out;
    return 0;
}
