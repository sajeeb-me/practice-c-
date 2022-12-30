#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int>arr;
    arr.resize(n-1);

    vector<int>newArr;
    newArr.resize(n);

    for(int i=0; i<n; i++)
        newArr[i]=0;

    for(int i=0; i<n-1; i++)
        cin >> arr[i];

    for(int i=0; i<n-1; i++)
        newArr[arr[i]-1] = 1;

     for(int i=0; i<n; i++)
     {
         if(newArr[i]==0)
            cout << i+1 << "\n";
     }

    return 0;
}
