#include<bits/stdc++.h>

using namespace std;

/*

Time complexity = O(n + ((n-1)*n)/2) = O((n^2 - n)/2) = O( n^2/2 - n/2 ) = O(n^2/2) = O(n^2)
Memory complexity = O(n)

*/

int main()
{
    int n; // O(1)
    cin >> n;
    vector<int>a(n); //O(n)
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    for(int i=0; i<n; i++)
    {
        string ans = "NO\n";
        for(int j=i+1; j<n; j++)
        {
            if(a[i]==a[j])
                ans = "YES\n";
        }
        cout << "i = " << i << " " << ans;
    }

    return 0;
}

