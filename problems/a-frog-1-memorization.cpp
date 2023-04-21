#include<bits/stdc++.h>
using namespace std;

const int N = 10e3;

int h[N], arr[N];

int cost(int n)
{
    if(n == 1) return 0;
    if(arr[n] != -1) return arr[n];

    int ans1 = cost(n-1)+abs(h[n]-h[n-1]);
    if(n == 2)
    {
        arr[n] = ans1;
        return arr[n];
    }
    int ans2 = cost(n-2)+abs(h[n]-h[n-2]);

    arr[n] = min(ans1, ans2);
    return arr[n];
}


int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> h[i];
        arr[i] = -1;
    }

    cout << cost(n) << "\n";

    return 0;
}
