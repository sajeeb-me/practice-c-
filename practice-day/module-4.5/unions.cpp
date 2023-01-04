#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];

    int m;
    cin >> m;
    vector<int>arr2(m);
    for(int i=0; i<m; i++)
        cin >> arr2[i];


    for(int i=0; i<n; i++)
    {
        bool flag = false;
        for(int j=0; j<m; j++)
        {
            if(arr[i]==arr2[j])
            {
                flag = true;
                break;
            }
        }
        if(!flag)
        {
            arr2.push_back(arr[i]);
        }
    }

    sort(arr2.begin(), arr2.end());

    for(int i=0; i<arr2.size(); i++)
        cout << arr2[i] << " ";
    cout << "\n";

    return 0;
}

