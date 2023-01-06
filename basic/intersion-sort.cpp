#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];

    for(int i=1; i<n; i++)
    {
        int idx = i;
        while(idx >= 1)
        {
            if(arr[idx-1]>arr[idx])
            {
                swap(arr[idx-1], arr[idx]);
                idx--;
            }
            else
                break;
        }

        cout << "count: " << i << "-> ";
        for(int i=0; i<n; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }

    cout << "after sorted :";
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";

    return 0;
}

/*
5
5 4 3 2 1
*/

