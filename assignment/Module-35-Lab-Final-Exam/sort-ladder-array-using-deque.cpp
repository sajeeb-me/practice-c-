#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    deque<int> arr;
    for(int i=0; i<n; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    vector<int> ans;
    while(arr.size())
    {
        if(arr.front() > arr.back())
        {
            ans.push_back(arr.back());
            arr.pop_back();
        }
        else
        {
            ans.push_back(arr.front());
            arr.pop_front();
        }
    }

    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}
