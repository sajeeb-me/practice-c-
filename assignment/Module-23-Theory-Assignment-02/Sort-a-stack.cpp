#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;
    st.push(3);
    st.push(4);
    st.push(6);
    st.push(2);
    st.push(5);

    // sort
    stack<int> tmp;
    while(!st.empty())
    {
        int t = st.top();
        st.pop();
        while(!tmp.empty() && tmp.top() < t)
        {
            st.push(tmp.top());
            tmp.pop();
        }
        tmp.push(t);
    }
    swap(tmp, st);
    while(!st.empty())
    {
        cout << st.top()<< "\n";
        st.pop();
    }

    return 0;
}
