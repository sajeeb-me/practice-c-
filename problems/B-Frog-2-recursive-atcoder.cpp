#include<bits/stdc++.h>
using namespace std;

const int N = 1e3;
const int INF = 1e9;

int h[N], dp[N];
int n, k;

int minCost(int n)
{
    if(n == 1) return 0;
    if(dp[n] != -1) return dp[n];

    int ans = INF;
    for(int i=1; i<=k; i++)
    {
        if(n-i <= 0) break;
        int candidate_ans = minCost(n-i)+abs(h[n] - h[n-i]);
        ans = min(ans, candidate_ans);
    }
    dp[n] = ans;
    return ans;
}

int main()
{
    cin >> n >> k;
    for(int i=1; i<=n; i++)
    {
        cin >> h[i];
        dp[i] = -1;
    }

    cout << minCost(n) << "\n";

    return 0;
}
