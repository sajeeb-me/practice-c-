#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int>c(n);
    for(int i=0; i<n; i++)
        cin >> c[i];

    vector<int>d(q);
    for(int i=0; i<q; i++)
        cin >> d[i];

    sort(c.begin(), c.end());


    for(int i=0; i<q; i++)
    {
        int low = 0, high = n-1;
        bool flag = false;
        int k = d[i];

        while(low<=high)
        {
            int mid = (high+low)/2;
            if(c[mid] == k)
            {
                cout << k << ": " << "YES " << "\n";
                flag = true;
                break;
            }
            if(c[mid] > k)
                high = mid-1;
            if(c[mid] < k)
                low = mid+1;
        }
        if(!flag)
        {
            cout << k << ": " << "NO " << "\n";
        }
    }

    return 0;
}


/*
10 3
16 5 30 10 19 18 32 14 35 15
8 12 32

10 3
4 5 8 12 15 20 21 32 34 40
8 12 32
*/

