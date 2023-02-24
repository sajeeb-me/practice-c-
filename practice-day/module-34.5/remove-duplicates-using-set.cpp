#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];

    set<int> st;
    for(int i=0; i<n; i++)
        st.insert(arr[i]);

    for(auto it:st)
        cout << it << " ";
    cout << "\n";

    return 0;
}

