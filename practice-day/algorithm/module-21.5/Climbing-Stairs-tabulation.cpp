// problem link: https://leetcode.com/problems/climbing-stairs/

#include<bits/stdc++.h>
using namespace std;

/*
time complexity: O(n)
space complexity: O(n)
*/

int main()
{
    int n;
    cin >> n;

    vector<int>dp(n+1, 0);

    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<=n; i++)
        dp[i] = dp[i-1]+dp[i-2];

    cout << dp[n] << "\n";

    return 0;
}
