#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];

    int a, b;
    cin >> a >> b;

    arr.erase(arr.begin()+a-1, arr.begin()+b);

    for(int i=0; i<arr.size(); i++)
        cout << arr[i] << " ";

    return 0;
}
