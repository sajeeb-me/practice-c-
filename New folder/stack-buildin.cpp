#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << st.top() << "\n";
    cout << "Size: " << st.size() << "\n";
    st.pop();
    st.pop();
    cout << st.top() << "\n";
    st.pop();
    cout << "Size: " << st.size() << "\n";

    return 0;
}
