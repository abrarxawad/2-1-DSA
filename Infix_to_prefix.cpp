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

int main()
{
    string s;
    cin >> s;
    reverse(s.begin(), s.end());

    stack<char> st;
    string ans = "";

    for (int i = 0; i < s.size(); i++)
    {
        // operand
        if ((isalnum(s[i])))
        {
            ans += s[i];
        }

        else if (s[i] == ')')
        {
            st.push('(');
        }

        else if (s[i] == '(')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }

        else
        {
            if (s[i] == '^')
            {
                while (!st.empty() &&
                       prec(s[i]) <= prec(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            else
            {
                while (!st.empty() &&
                       prec(s[i]) < prec(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());

    cout << ans << endl;
}
