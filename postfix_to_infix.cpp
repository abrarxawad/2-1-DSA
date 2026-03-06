#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    stack<string> st;

    for (int i = 0; i < s.size(); i++)
    {
        if (isalnum(s[i]))
        {
            st.push(string(1, s[i]));
        }
        else
        {
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();

            st.push("(" + op1 + s[i] + op2 + ")");
        }
    }
    cout << st.top() << endl;

    return 0;
}