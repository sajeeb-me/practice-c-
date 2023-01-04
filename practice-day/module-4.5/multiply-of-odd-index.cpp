#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];

    int result = 1;
    for(int i=0; i<n; i++)
    {
        if(i%2==1)
            result *= arr[i];
    }

    cout << result << "\n";

    return 0;
}

