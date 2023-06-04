#include<bits/stdc++.h>
using namespace std;

int findKing(vector<int>blocks, int n)
{
    int total = 0;
    int left = 0;

    for(int i=0; i<n; i++) total += blocks[i];

    for(int i=0; i<n; i++)
    {
        total -= blocks[i];

        if(total == left) return i;

        left += blocks[i];
    }

    return -1;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        vector<int>blocks(n+1);
        for(int i=0; i<n; i++) cin >> blocks[i];

        cout << findKing(blocks, n) << "\n";
    }

    return 0;
}
