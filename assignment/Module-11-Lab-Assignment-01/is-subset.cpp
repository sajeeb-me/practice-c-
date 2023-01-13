#include<bits/stdc++.h>
using namespace std;

bool isSubset(int n, vector<int>a, vector<int>b)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i=0, j=0;

    while(i<a.size() && j<b.size())
    {
        if(a[i] < b[j])
            return false;
        if(a[i] == b[j])
            i++;
        j++;
    }

    return (i == n);
}

int main()
{
    int n1;
    cin >> n1;
    vector<int>arr1(n1);
    for(int i=0; i<n1; i++)
        cin >> arr1[i];

    int n2;
    cin >> n2;
    vector<int>arr2(n2);
    for(int i=0; i<n2; i++)
        cin >> arr2[i];

    if(isSubset(n1, arr1, arr2))
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";

    return 0;
}
