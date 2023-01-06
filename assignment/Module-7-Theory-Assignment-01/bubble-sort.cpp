#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-1-i; j++)
        {
            if(arr[j]>arr[j+1])
                swap(arr[j], arr[j+1]);

            for(int i=0; i<n; i++)
                cout << arr[i] << " ";
            cout << "\n";
        }
    }

    cout << "after sorting: ";
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";

    return 0;
}

/*
6
7 2 13 2 11 4
*/
