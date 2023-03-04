#include<bits/stdc++.h>
using namespace std;

vector<string>merge_sort(vector<string>a)
{
    if(a.size() <= 1)
        return a;

    int mid = a.size()/2;
    vector<string>b;
    vector<string>c;

    for(int i=0; i<mid; i++)
        b.push_back(a[i]);
    for(int i=mid; i<a.size(); i++)
        c.push_back(a[i]);

    vector<string>sorted_b = merge_sort(b);
    vector<string>sorted_c = merge_sort(c);

    vector<string>sorted_a;
    int idxb = 0, idxc = 0;
    for(int i=0; i<a.size(); i++)
    {
        if(idxb == sorted_b.size())
        {
            sorted_a.push_back(sorted_c[idxc]);
            idxc++;
        }
        else if(idxc == sorted_c.size())
        {
            sorted_a.push_back(sorted_b[idxb]);
            idxb++;
        }
        else if(sorted_b[idxb] < sorted_c[idxc])
        {
            sorted_a.push_back(sorted_b[idxb]);
            idxb++;
        }
        else
        {
            sorted_a.push_back(sorted_c[idxc]);
            idxc++;
        }
    }
    return sorted_a;
}

int main()
{
    int n;
    cin >> n;
    vector<string> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    vector<string> ans = merge_sort(arr);
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}
