#include <bits/stdc++.h>
using namespace std;

class Stackk
{
public:
    int topindex;
    int size;
    int *arr;
    Stackk(int cap = 100)
    {
        size = cap;
        topindex = -1;
        arr = new int[size];
    }
    int push(int x)
    {
        topindex++;
        arr[topindex] = x;
        return arr[topindex];
    }

    int pop()
    {
        return arr[topindex--];
    }
    int top()
    {
        return arr[topindex];
    }

    bool isempty()
    {
        if (topindex == -1)
        {
            return true;
        }
        return false;
    }
};

int prec(char c)
{
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return -1;
}

int main()
{
    string s;
    cin >> s;

    Stackk st;
    string ans = "";

    for (int i = 0; i < s.size(); i++)
    {
        // operand
        if ((isalnum(s[i])))
        {
            ans += s[i];
        }

        else if (s[i] == '(')
        {
            st.push(s[i]);
        }

        else if (s[i] == ')')
        {
            while (!st.isempty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            if (!st.isempty())
                st.pop();
                //popping (
        }

        else
        {
            while (!st.isempty() &&
                   prec(s[i]) <= prec(st.top()))
            {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.isempty())
    {
        ans += st.top();
        st.pop();
    }

    cout << ans << endl;
}