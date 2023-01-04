#include<bits/stdc++.h>

using namespace std;

int main()
{
    int k=1;
    while(k<=n)
    {
        cout<<k<<endl;
        k=k*2;
    }
    /*
    Time complexity = O(logn);
    */
    // ===============================================


    for (int i = 0; i < n; i++)
        for (int j = i; j > 0; j--)
            cout << i << j;
    /*
    Time complexity = O(n*n) = O(n^2);
    */
    // ===============================================


    for (int i = 0; i < n; i++)
        for (int j = i; j > 0; j--)
            for(int k=j; k > 0; k--)
                cout << i << j << k;
    /*
    Time complexity = O(n*n*n) = O(n^3);
    */
    // ===============================================


    for(int i=n/2; i<=n; i++)
    {
        for(int j=1; j<=n; j=j*2)
        {
            cout<<i<<j<<endl;
        }
    }
    /*
    Time complexity = O(n/2 * logn) = O();
    */
    // ===============================================


    for(int i=n/2; i<=n; i++)
    {
        for(int j=1; j<=n; j=j+i)
        {
            cout<<i<<j<<endl;
        }
    }
    /*
    Time complexity = O(n/2 * n);
    */
    // ===============================================


    for(int i=1; i<=n; i++)
    {
        if(builtin_popcount(i) == 1)
        {
            for(int j=1; j<=n; j++)
                cout<<i<<j<<endl;
        }
    }
    /*
    Time complexity = best case = O(n), worst case = O(n^2);
    */
    // ===============================================

    return 0;
}
