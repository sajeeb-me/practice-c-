#include<bits/stdc++.h>
using namespace std;

int getSum(vector<int>arr, int num)
{
    if(num < 0) return 0;
    return arr[num]+getSum(arr, num-1);
}

int main()
{
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    int sum = getSum(arr, n-1);
    cout << sum << "\n";

    return 0;
}
