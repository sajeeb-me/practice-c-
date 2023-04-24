#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int dp[N];

int fibonacci(int n)
{
    if(n == 0) return 0;
    if(n <= 2) return 1;
    if(dp[n] != -1) return dp[n];
    dp[n] = fibonacci(n-1) + fibonacci(n-2);
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) dp[i] = -1;
    cout << fibonacci(n) << "\n";
    return 0;
}
