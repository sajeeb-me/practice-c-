#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];

    int m;
    cin >> m;
    vector<int>b(m);
    for(int i=0; i<m; i++)
        cin >> b[i];

    sort(a.begin(), a.end());

    for(int i=0; i<m; i++)
    {
        int k = b[i];
        int low=0, high=n-1;
        bool found = false;
        for(int j=0; j<n; j++)
        {
            int mid = (low+high)/2;
            if(k==mid)
            {
                cout << "YES\n";
                found = true;
                break;
            }
            if(mid>k)
            {
                high = mid-1;
            }
            if(mid<k)
            {
                low = mid+1;
            }
        }
        if(!found)
        {
            cout << "NO\n";
        }
    }

    return 0;
}
