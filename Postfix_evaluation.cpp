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

int apply(int x, int y, char c)
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

    for (char c : s)
    {

        if (isdigit(c))
        {
            st.push(c - '0');
        }
        else
        {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            st.push(apply(a, b, c));
        }
    }
    cout << st.top() << endl;

    return 0;
}
