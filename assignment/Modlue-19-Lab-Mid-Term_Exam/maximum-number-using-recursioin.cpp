#include<bits/stdc++.h>
using namespace std;

int maximumElement(vector<int>a, int sz)
{
    if(sz == 1)
        return a[0];

    int maxx;
    maxx = maximumElement(a, sz-1);
    if(a[sz-1] > maxx)
        maxx = a[sz-1];

    return maxx;
}

int main()
{
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    int sz = arr.size();
    cout << maximumElement(arr, sz);

    return 0;
}
