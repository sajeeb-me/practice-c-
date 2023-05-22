#include<bits/stdc++.h>
using namespace std;

const int N = 1e9;

long long n, x;
map<long long, long long> dp;

vector<long long> getDigits(long long num)
{
    vector<long long> digits;

    while(num)
    {
        digits.push_back(num%10);
        num /= 10;
    }
//    for(auto dig : digits) cout << dig << " ";
//    cout << "\n";
    return digits;
}

long long dfs(long long x)
{
    string str = to_string(x);
    int length = str.size();
    if(length == n)  return 0;
    if(length > n )  return N;
    if(dp.count(x))  return dp[x];

    long long ans = N;

    for(auto digit : getDigits(x))
    {
        if(digit==1 || digit==0) continue;

        ans = min(1 + dfs(x*digit), ans);
    }

    return dp[x] = ans;
}

int main()
{
    cin>> n >> x;

    cout << (dfs(x) == N ? -1 : dfs(x));

    return 0;
}
