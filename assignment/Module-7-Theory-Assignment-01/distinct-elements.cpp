#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0; i<n; i++)
        cin>>a[i];
    sort(a.begin(),a.end());

//    cout << "after sorting: ";
//    for(int i=0; i<n; i++)
//        cout << a[i] << " ";
//    cout << "\n";

    int ans = 1;
    for(int i=1 ; i<n ; i++)
        if(a[i]!=a[i-1])
        {
//            cout << "a[i] = " << a[i] << " i = " << i << " ";
//            cout << "a[i-1] = " << a[i-1] << " i-1 = " << i-1 << "\n";
            ans++;
        }
    cout<<ans;
    return 0;
}

