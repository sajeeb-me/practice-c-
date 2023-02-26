#include<bits/stdc++.h>
using namespace std;

int main()
{
    string breakets;
    cin >> breakets;
    stack<char> st;
    for(int i=0; i<breakets.size(); i++)
    {
        char tmp = breakets[i];
        if(tmp == '(' || tmp == '{' || tmp == '[')
            st.push(tmp);
        else
        {
            if(st.empty())
            {
                cout << "No\n";
                return 0;
            }
            else if(st.top() == '(' && tmp == ')')
                st.pop();
            else if(st.top() == '{' && tmp == '}')
                st.pop();
            else if(st.top() == '[' && tmp == ']')
                st.pop();
            else
            {
                cout << "No\n";
                return 0;
            }
        }
    }
    if(st.empty())
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
