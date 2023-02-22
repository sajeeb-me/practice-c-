#include<bits/stdc++.h>
using namespace std;

int main()
{
    set<int> st;
    st.insert(5);
    st.insert(4);
    st.insert(8);
    st.insert(2);
    st.insert(6);
    st.insert(5);

    for(auto it:st)
        cout << it << " ";
    cout << "\n";

    st.erase(5);

    for(auto it:st)
        cout << it << " ";
    cout << "\n";

    if(st.find(6) != st.end())
        cout << "6 exist!\n";
    else
        cout << "6 does not exist!\n";

    return 0;
}
