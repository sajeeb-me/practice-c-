#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;

    cin >> a;
    vector<int> arr1(a);
    for(int i=0; i<a; i++)
        cin >> arr1[i];

    cin >> b;
    vector<int> arr2(b);
    for(int i=0; i<b; i++)
        cin >> arr2[i];

    set<int> st;
    for(int i=0; i<a; i++)
        st.insert(arr1[i]);
    for(int i=0; i<b; i++)
        st.insert(arr2[i]);

    for(auto it:st)
        cout << it << " ";
    cout << "\n";

    return 0;
}
