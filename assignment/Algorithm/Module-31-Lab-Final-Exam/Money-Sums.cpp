#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int dp[N];

int main()
{
    int n;
    cin >> n;
    vector<int>arr(n+1);
    vector<int>sums;

    int total = 0;
    for(int i=1; i<=n; i++)
    {
        cin >> arr[i];
        total += arr[i];
    }

    dp[0] = 1;
    for(int i=1; i<=n; i++)
        for(int j=total; j>=arr[i]; j--)
            dp[j] += dp[j-arr[i]];

    for(int i=1; i<=total; i++)
        if(dp[i])
            sums.push_back(i);

    cout << sums.size() << "\n";
    for(int i=0; i<sums.size(); i++)
        cout << sums[i] << " ";

    return 0;
}
