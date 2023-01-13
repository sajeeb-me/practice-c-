#include<bits/stdc++.h>
using namespace std;

int missing_num(int n, vector<int>a)
{
    vector<int>new_arr(n+1, 0);
    for(int i=0; i<a.size(); i++)
        new_arr[a[i]] = 1;

    int ans;
    for(int i=1; i<new_arr.size(); i++)
        if(new_arr[i] == 0)
            ans = i;

    return ans;
}

int main()
{
    int num;
    cin >> num;
    vector<int>arr(num-1);
    for(int i=0; i<num-1; i++)
        cin >> arr[i];

    int ans = missing_num(num, arr);
    cout << ans;

    return 0;
}
