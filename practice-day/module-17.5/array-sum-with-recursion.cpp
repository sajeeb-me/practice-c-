#include<bits/stdc++.h>
using namespace std;

int arraySum(vector<int>a, int size)
{
    if(size == 0)
        return 0;
    return a[size-1]+arraySum(a, size-1);
}

int main()
{
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    int size = arr.size();
    int ans = arraySum(arr, size);
    cout << ans;

    return 0;
}
