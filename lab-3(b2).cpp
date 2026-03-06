/*Given a infix with space, comma and digits  . first of all, design a
function to make the infix clear without space, comma and print it.
Secondly make the infix convert to postfix and print it.
evaluate the postfix and print the answer .
*/

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

string cleanInfix(string s)
{
    string r = "";
    for (char c : s)
    {
        if (c != ' ' && c != ',')
            r += c;
    }
    return r;
}

string infixToPostfix(string s)
{
    stackk st;
    string res = "";

    for (char c : s)
    {
        if (isdigit(c))
        {
            res += c;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (!st.isempty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            if (!st.isempty())
                st.pop();
        }
        else
        { 
            while (!st.isempty() && prec(st.top()) >= prec(c))
            {
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.isempty())
    {
        res += st.top();
        st.pop();
    }

    return res;
}

int evalPostfix(string post)
{
    stackk st;

    for (char c : post)
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

            if (c == '+')
                st.push(a + b);
            else if (c == '-')
                st.push(a - b);
            else if (c == '*')
                st.push(a * b);
            else if (c == '/')
                st.push(a / b);
            else if (c == '^')
                st.push(pow(a, b));
        }
    }
    return st.top();
}

int main()
{
    string infix;
    cout << "Enter infix with space & comma: ";
    getline(cin, infix);

    string clean = cleanInfix(infix);
    cout << "Clean infix: " << clean << endl;

    string postfix = infixToPostfix(clean);
    cout << "Postfix: " << postfix << endl;

    cout << "Answer: " << evalPostfix(postfix) << endl;
}
