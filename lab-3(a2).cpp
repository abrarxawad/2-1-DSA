/*Input: The value of { a + b * ( c ^ d - e ) ^ ( f + g * h ) - i }
and { x+y*z/w+u } are differrent. Now here print the infix available in the code
and convert the infix to postfix and print the number of operands and operators
*/

#include <bits/stdc++.h>
using namespace std;

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

string clean(string s)
{
    string r = "";
    for (char c : s)
        if (c != ' ')
            r += c;
    return r;
}

string infixToPostfix(string s)
{
    stack<char> st;
    string res = "";

    for (char c : s)
    {

        if (isalnum(c))
        {
            res += c;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && prec(st.top()) >= prec(c))
            {
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }

    return res;
}

void countOp(string s, int &operands, int &operators)
{
    operands = 0;
    operators = 0;

    for (char c : s)
    {
        if (isalnum(c))
            operands++;
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
            operators++;
    }
}

int main()
{

    string line, tempp;
    while(getline(cin, tempp)){
        line += tempp;
    }

    vector<string> expressions;
    string temp = "";
    bool inside = false;

    for (char c : line)
    {
        if (c == '{')
        {
            inside = true;
            temp = "";
        }
        else if (c == '}')
        {
            inside = false;
            expressions.push_back(temp);
        }
        else if (inside)
        {
            temp += c;
        }
    }

    for (int i = 0; i < expressions.size(); i++)
    {

        string infix = clean(expressions[i]);

        cout << infix << endl;

        string postfix = infixToPostfix(infix);
        cout <<postfix << endl;

        int operands, operators;
        countOp(infix, operands, operators);

        cout <<  operands << endl;
        cout <<  operators << endl;
        cout << endl;
    }

    return 0;
}
