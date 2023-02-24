#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];

    map<int, int> mp;
    for(int i=0; i<n; i++)
        mp[arr[i]]++;

    for(auto it:mp)
        cout << it.first << ": " << it.second << "\n";

    return 0;
}
