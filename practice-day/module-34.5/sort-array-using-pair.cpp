#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int,int>> arr(n);
    for(int i=0; i<n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i;
    }

//    sort(arr.begin(), arr.end());

    for(auto it:arr)
        cout << "Value " << it.first << ", Previous index " << it.second << "\n";



    return 0;
}
