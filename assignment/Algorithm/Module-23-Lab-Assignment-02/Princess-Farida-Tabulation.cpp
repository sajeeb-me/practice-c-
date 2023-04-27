#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
long long arr[N];
long long dp[N];

int main()
{
    int t;
    cin >> t;
    for(int i=1; i<=t; i++)
    {
        int n;
        cin >> n;
        for(int j=0; j<n; j++)
            cin >> arr[j];

        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);
        for(int j=2; j<n; j++)
            dp[j] = max(dp[j-2]+arr[j], dp[j-1]);

        cout << dp[n-1] << "\n";
    }
    return 0;
}
