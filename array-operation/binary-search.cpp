#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int>c(n);

    for(int i=0; i<n; i++)
        cin >> c[i];

    int low = 0, high = n-1;
    bool flag = false;

    while(low<=high)
    {
        int mid = (high+low)/2;
        if(c[mid] == k)
        {
            cout << "YES " << mid << "\n";
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
        cout << "NO " << "\n";
    }

    return 0;
}


/*
10 18
4 5 6 10 14 18 32 34 35 40
*/
