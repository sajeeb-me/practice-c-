// problem link: https://leetcode.com/problems/min-cost-climbing-stairs/

#include<bits/stdc++.h>
using namespace std;

/*
time complexity: O(n)
space complexity: O(n)
*/

int getMax(vector<int>& dp, vector<int>& nums, int i)
{
    if(i < 0) return 0;
    if(dp[i] != -1) return dp[i];
    dp[i] = max(getMax(dp, nums, i-1) , nums[i]+getMax(dp, nums, i-2));
    return dp[i];
}

int rob(vector<int>& nums)
{
    int n = nums.size();
    vector<int>dp(n+1, -1);
    return getMax(dp, nums, n-1);
}

int main()
{
    vector<int>nums = {1,3,1};

    cout << rob(nums) << "\n";

    return 0;
}
