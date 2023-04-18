// problem link: https://leetcode.com/problems/climbing-stairs/

#include<bits/stdc++.h>
using namespace std;

/*
time complexity: O(n)
space complexity: O(n)
*/

int climbStairs(int n)
{
    vector<int>dp(n+1, 0);
    if(n <= 1) return 1;    // base case
    if(dp[n]) return dp[n];   // dp state
    dp[n] = climbStairs(n-1) + climbStairs(n-2);   // relation
    return dp[n];
}

int main()
{
    int n;
    cin >> n;

    cout << climbStairs(n) << "\n";

    return 0;
}
