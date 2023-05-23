#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> arr(n+1);
    for (int i=1; i<=n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i;
    }

    sort(arr.begin(), arr.end());

    int i=1, j=n;
    while (i<j)
    {
        int ans = arr[i].first + arr[j].first;
        if (ans == x)
        {
            cout << arr[i].second << " " << arr[j].second << "\n";
            return 0;
        }
        else if (ans<x) i++;
        else j--;
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
