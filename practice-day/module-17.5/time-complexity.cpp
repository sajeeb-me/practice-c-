#include<bits/stdc++.h>
using namespace std;

/*
Time complexity: O(log n * n) = O(n log n)

    for(int k=1;k<=n;k=k*2) = O(log n)
    {
        for(int i=1;i<=n;i++)  = O(n)
        {
            cout<<k<<" "<<i<<"\n";
        }
    }
====================================


Time complexity: O(n)

    for(int k=1; k<=n; k++)  = O(n)
    {
        if(k==1) = Constant time = O(1)
        {
            for(int i=1; i<=n; i++)
            {
                cout<<k<<" "<<i<<"\n";
            }
        }
    }
====================================


Time complexity: O(n * n) = O(n^2)

    for(int k=1; k<=n; k++)     = O(n)
    {
        if(k%2==0)
        {
            for(int i=1; i<=n; i++) = O(n)
            {
                cout<<k<<" "<<i<<"\n";
            }
        }
    }
====================================

*/

int main()
{
    int n=10;
    for(int k=1; k<=n; k++)
    {
        if(k%2==0)
        {
            for(int i=1; i<=n; i++)
            {
                cout<<k<<" "<<i<<"\n";
            }
        }
    }



    return 0;
}
