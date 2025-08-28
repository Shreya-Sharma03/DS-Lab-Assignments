// 4) String Related Programs

// (a) Write a program to concatenate one string to another string.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    char str1[25], str2[25];
    cin >> str1 >> str2;
    cout << "String 1: " << str1 << endl;
    cout << "String 2: " << str2 << endl;
    int a = strlen(str1), b = strlen(str2);
    for (int i = a; i < a + b; i++)
    {
        str1[i] = str2[i - a];
    }
    str1[a + b] = '\0';
    cout << "Concatenated String: " << str1 << endl;
    return 0;
}

// (b) Write a program to reverse a string.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    char str[15];
    cin >> str;
    cout << "Original String: " << str << endl;
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i];
        str[len - i] = temp;
    }
    cout << "String after reversing: " << str << endl;
    return 0;
}

// (c) Write a program to delete all the vowels from the string.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    char str[15], str1[15];
    cin >> str;
    cout << "Original String: " << str << endl;
    int len = strlen(str);
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        if (!(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
              str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'))
        {
            str1[j] = str[i];
            j++;
        }
    }
    str1[j] = '\0';
    cout << "String after deleting vowels: " << str1 << endl;
    return 0;
}

// (d) Write a program to sort the strings in alphabetical order.
#include <bits/stdc++.h>
    using namespace std;
int main()
{
    char str[15];
    cin >> str;
    cout << "Original String: " << str << endl;
    int len = strlen(str);
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (str[j] > str[j + 1])
            {
                int temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
    cout << "String after sorting in alphabetical order: " << str << endl;
    return 0;
}

// (e) Write a program to convert a character from uppercase to lowercase.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    char ch;
    cin >> ch;
    cout << "Character in uppercase: " << ch << endl;
    if (ch >= 'A' && ch < 'Z')
        ch = ch + 32;
    cout << "Character in lowercase: " << ch << endl;
    return 0;
}
