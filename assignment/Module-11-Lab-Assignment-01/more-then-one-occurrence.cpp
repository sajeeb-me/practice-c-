#include<bits/stdc++.h>
using namespace std;

bool isMoreThenOne(vector<int>a, int n)
{
    int low = 0, high = a.size()-1, count_oc = 0;

    while(low<=high)
    {
        int mid = (low+high)/2;
        if(a[mid]==n)
        {
            count_oc++;
            if(a[mid] == a[mid-1] || a[mid] == a[mid+1])
            {
                count_oc++;
                return (count_oc > 1);
            }
            else
                return (count_oc > 1);
        }
        if(a[mid]<n)
            low = mid+1;
        if(a[mid]>n)
            high = mid-1;
    }
    return (count_oc > 1);
}

int main()
{
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    int k;
    cin >> k;
    if(isMoreThenOne(arr,k))
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";
    return 0;
}


/*
10
1 2 3 4 5 6 7 8 9 10
5

7
1 3 4 6 6 9 17
6
*/
