#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int dp[N];

int tribonacci(int n)
{
    if(n == 0) return 0;
    if(n <= 2) return 1;
    if(dp[n] != -1) return dp[n];
    dp[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
    return dp[n];
}

int main()
{
    int n;
    cin >> n;

    for(int i=1; i<=n; i++) dp[i] = -1;

    cout << tribonacci(n) << "\n";

    return 0;
}
