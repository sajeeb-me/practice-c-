#include<bits/stdc++.h>
using namespace std;

/*
dp state:
dp[N]

recurrence relation:
kth integer dp[n] = (n-1)+(n-2)+....+(n-k)

base case:
n <= k

time complexity = O(kn)
space complexity = O(k)
*/
const int N = 1e5 + 5;
vector<int>dp(N, -1);

int main()
{
    int n, k;
    cin >> n >> k;

    for(int i=1; i<=n; i++) dp[i] = 1;
    dp[n+1] = n;

    for(int i=n+2; i<=k; i++)
    {
        int ans = 0;
        for(int j=1; j<=n; j++)
            ans += dp[i-j];
        dp[i] = ans;
    }

    cout << dp[k] << "\n";

    return 0;
}
