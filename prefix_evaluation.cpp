#include <bits/stdc++.h>
using namespace std;

class stackk
{
public:
    int *arr;
    int size;
    int topindx;

    stackk(int cap = 100)
    {
        size = cap;
        arr = new int[size];
        topindx = -1;
    }
    int push(int x)
    {
        return arr[++topindx] = x;
    }
    int pop()
    {
        return arr[topindx--];
    }
    int top()
    {
        return arr[topindx];
    }
    bool isempty()
    {
        if (topindx == -1)
        {
            return true;
        }
        return false;
    }
};

/*int apply(int x, int y, char c)
{
    if (c == '+')
    {
        return x + y;
    }
    else if (c == '-')
    {
        return x - y;
    }
    else if (c == '*')
    {
        return x * y;
    }
    else if (c == '/')
    {
        return x / y;
    }
    else
    {
        return pow(x, y);
    }
}

int main()
{
    string s;
    cin >> s;

    stackk st;
    int ans = 0;

    for (int i = s.size(); i >= 0; i--)
    {
        char c = s[i];
        if (isdigit(c))
        {
            st.push(c - '0');
        }
        else
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(apply(a, b, c));
        }
    }
    cout << st.top() << endl;

    return 0;
}
*/

int countt(int x, int y, char c)
{
    if (c == '+')
    {
        return x + y;
    }
    if (c == '-')
    {
        return x - y;
    }
    if (c == '*')
    {
        return x * y;
    }
    if (c == '/')
    {
        return x / y;
    }
}

int main()
{
    string s;
    cin >> s;
    stackk st;

    for (int i = s.size() - 1; i >= 0; i--)
    {
        char c = s[i];
        if (isalnum(c))
        {
            st.push(c-'0');
        }
        else
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();

            st.push(countt(a, b, c));
        }
    }
    cout<<st.top()<<endl;
}