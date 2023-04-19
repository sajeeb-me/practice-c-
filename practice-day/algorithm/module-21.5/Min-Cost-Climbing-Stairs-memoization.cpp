// problem link: https://leetcode.com/problems/min-cost-climbing-stairs/

#include<bits/stdc++.h>
using namespace std;

/*
time complexity: O(n)
space complexity: O(n)
*/

int minCost(vector<int>& cost, int n)
{
    if(n < 0) return 0;
    if(n == 0 || n == 1) return cost[n];
    return cost[n] + min(minCost(cost, n-1), minCost(cost, n-2));
}

int minCostClimbingStairs(vector<int>& cost)
{
    int n = cost.size();
    return min(minCost(cost, n-1), minCost(cost, n-2));
}

int main()
{
    vector<int>cost = {1,100,1,1,1,100,1,1,100,1};

    cout << minCostClimbingStairs(cost) << "\n";

    return 0;
}
