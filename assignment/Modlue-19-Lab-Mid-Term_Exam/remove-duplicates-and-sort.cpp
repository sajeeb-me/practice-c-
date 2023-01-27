#include<bits/stdc++.h>
using namespace std;

void removeDuplicate(vector<int>a)
{
    vector<int>uniqueArray;

    for(int i=0; i<a.size(); i++)
        if(count(uniqueArray.begin(), uniqueArray.end(), a[i]) == 0)
            uniqueArray.push_back(a[i]);

    sort(uniqueArray.begin(), uniqueArray.end());

    for(int i=0; i<uniqueArray.size(); i++)
        cout << uniqueArray[i] << " ";
}

int main()
{
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    removeDuplicate(arr);

    return 0;
}
