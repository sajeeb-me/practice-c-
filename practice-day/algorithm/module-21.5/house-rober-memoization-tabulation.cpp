// problem link: https://leetcode.com/problems/min-cost-climbing-stairs/

#include<bits/stdc++.h>
using namespace std;

/*
time complexity: O(n)
space complexity: O(n)
*/

int rob(vector<int>& nums)
{
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    vector<int> dp(n+1);
    dp[0] = 0; dp[1] = nums[0];

    for (int i = 2; i <= n; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
    }

    return dp[n];
}

int main()
{
    vector<int>nums = {1,3,1};

    cout << rob(nums) << "\n";

    return 0;
}

