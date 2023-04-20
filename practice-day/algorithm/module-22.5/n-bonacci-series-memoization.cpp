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

int nBonacci(int n, int k)
{
    if(k<=n) return 1;
    if(dp[k] != -1) return dp[k];

    int ans = 0;
    for(int i=1; i<=n; i++)
        ans += nBonacci(n, k-i);

    dp[k] = ans;
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;

    cout << nBonacci(n, k) << "\n";

    return 0;
}
