#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
long long arr[N];
long long dp[N];

long long coins(int i)
{
    if(i < 0) return 0;
    if(i == 0) return arr[0];
    if(i == 1) return max(arr[0], arr[1]);
    if(dp[i] != -1) return dp[i];

    dp[i] = max(coins(i-2)+arr[i], coins(i-1));
    return dp[i];
}

int main()
{
    int t;
    cin >> t;
    for(int i=1; i<=t; i++)
    {
        int n;
        cin >> n;
        for(int j=0; j<n; j++)
        {
            cin >> arr[j];
            dp[j] = -1;
        }
        cout << coins(n-1) << "\n";
    }
    return 0;
}
