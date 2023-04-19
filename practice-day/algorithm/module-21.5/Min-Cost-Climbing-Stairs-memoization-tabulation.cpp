// problem link: https://leetcode.com/problems/min-cost-climbing-stairs/

#include<bits/stdc++.h>
using namespace std;

/*
time complexity: O(n)
space complexity: O(n)
*/

int minCostClimbingStairs(vector<int>& cost)
{
    int n = cost.size();
    vector<int> dp(n+1, 0);

    // base cases
    dp[0] = cost[0];
    dp[1] = cost[1];

    // dynamic programming
    for (int i = 2; i <= n; i++)
        dp[i] = min(dp[i-1], dp[i-2]) + (i < n ? cost[i] : 0);

    return dp[n];
}

int main()
{
    vector<int>cost = {1,100,1,1,1,100,1,1,100,1};

    cout << minCostClimbingStairs(cost) << "\n";

    return 0;
}

