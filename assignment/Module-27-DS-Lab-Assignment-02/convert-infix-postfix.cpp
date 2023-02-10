#include<bits/stdc++.h>
using namespace std;

int comp(char c)
{
    if(c == '+' || c == '-')
        return 1;
    else if(c == '*' || c == '/')
        return 2;
    else
        return 0;
}

int main()
{
    string s;
    cin >> s;
    stack<char>st;
    string ans = "";
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
            ans += s[i];
        else
        {
            if(s[i] == '(')
                st.push(s[i]);
            else if(s[i] == ')')
            {
                while(st.size() && st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while(st.size() && comp(st.top()) >= comp(s[i]))
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
    }
    while(st.size())
    {
        ans += st.top();
        st.pop();
    }
    cout << ans << "\n";

    return 0;
}
