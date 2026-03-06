/*The problem says:

You must check whether a string is a palindrome
✔ ignore spaces
✔ ignore punctuation
✔ ignore capitalization
✔ must use STACK*/

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{

    string clean = "";
    for (char c : s)
    {
        if (isalnum(c))
        {
            clean += tolower(c);
        }
    }
    int n = clean.length();

    char stackarr[n];

    int topindx = 0;
    for (int i = 0; i < n; i++)
    {
        stackarr[++topindx] = clean[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (clean[i] != stackarr[topindx--])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string s;
    getline(cin, s);

    bool flag = isPalindrome(s);

    if (flag)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}