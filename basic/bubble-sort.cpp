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
        int last = n-1-i;
        bool sorted = true;
        for(int j=0; j<last; j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                sorted = false;
            }
        }
        if(sorted)
            break;

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
