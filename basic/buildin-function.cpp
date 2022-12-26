#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a=5, b=3, c=2, d=8;
    int mini = min(a,b);
    cout << mini << "\n";

    int maxi = max(a,b);
    cout << maxi << "\n";

    int min_num = min({a,b,c,d});
    cout << min_num << "\n";

    vector<int>x = {5,8,9,1,2,4,6};
    sort(x.begin(), x.end());

    for(int i=0; i<x.size(); i++)
        cout << x[i] << " ";
    cout << "\n";

    return 0;
}
