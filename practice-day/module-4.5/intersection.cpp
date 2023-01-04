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

    vector<int>newArr;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(arr[i]==arr2[j])
            {
                newArr.push_back(arr[i]);
                break;
            }
        }
    }

    for(int i=0; i<newArr.size(); i++)
        cout << newArr[i] << " ";
    cout << "\n";

    return 0;
}


