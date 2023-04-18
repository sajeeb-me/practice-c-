#include<bits/stdc++.h>
using namespace std;

/*
time complexity: O(n)
space complexity: O(n)
*/

const int N = 101;
long long arr[N];

int main()
{
    int n;
    cin >> n;

    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 1;

    for(int i=4; i<=n; i++)
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];

    cout << arr[n] << "\n";

    return 0;
}
