#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long int n;
    cin >> n;

    cout << n << " ";
    while(1)
    {
        if(n==1)
            break;
        if(n%2==0)
        {
            n = n/2;
            cout << n << " ";
        }
        else
        {
            n = (n*3)+1;
            cout << n << " ";
        }
    }
    cout << "\n";


    return 0;
}
