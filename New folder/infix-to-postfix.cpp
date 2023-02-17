#include<bits/stdc++.h>
using namespace std;

int prec(char ch)
{
    if(ch == '+' || ch == '-')
        return 0;
    else
        return 1;
}

int main()
{
    string infix = "a*b+c*d+e";
    stack<int>st;
    string postfix = "";

    for(int i=0; i<infix.size(); i++)
    {
        char now = infix[i];
        if(now >='a' && now <= 'z')
            postfix += now;
        else
        {
            while(st.size() && prec(st.top()) >= prec(now))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(now);
        }
    }
    while(st.size())
    {
        postfix += st.top();
        st.pop();
    }
    cout << postfix << "\n";

    return 0;
}
