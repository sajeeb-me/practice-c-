#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rob(vector<int>& nums)
    {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];

        int n = nums.size()-1;
        vector<int> dp1(n+1, -1);
        vector<int> dp2(n+1, -1);

        return max(countMax(nums, 0, n-1, dp1), countMax(nums, 1, n, dp2));
    }

    int countMax(vector<int>& nums, int n, int lastHouse, vector<int>& dp)
    {
        if (n>lastHouse) return 0;
        if (dp[n] != -1) return dp[n];

        int ans1 = nums[n] + countMax(nums, n+2, lastHouse, dp);
        int ans2 = countMax(nums, n+1, lastHouse, dp);
        int ans = max(ans1, ans2);
        dp[n] = ans;
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,2,3,1};
    cout << s.rob(nums) << endl;
    return 0;
}
