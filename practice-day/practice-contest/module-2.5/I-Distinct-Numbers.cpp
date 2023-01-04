#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int>arr;
    arr.resize(n);

    for(int i=0; i<n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    int result = 1;
    for(int i=1; i<n; i++)
    {
        if(arr[i]!=arr[i-1])
            result++;
    }

    cout << result << "\n";

    return 0;
}
