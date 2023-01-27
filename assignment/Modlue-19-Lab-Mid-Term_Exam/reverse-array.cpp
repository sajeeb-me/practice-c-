#include<bits/stdc++.h>
using namespace std;

void reverseArray(vector<int>a, int sz)
{
    if(sz == 0)
        return;
    cout << a[sz-1] << " ";
    reverseArray(a, sz-1);
}

int main()
{
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    reverseArray(arr, n);

    return 0;
}
