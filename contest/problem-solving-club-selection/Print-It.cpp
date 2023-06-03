#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int totalPrint = n*2-1;

    for(int i=1; i<=totalPrint; i++)
    {
        int space = abs(n-i);
        int sign = 2*(n-space)-1;

        for(int j=0; j<space; j++) cout << " ";
        for(int j=0; j<sign; j++)
        {
            if(i%2==1) cout << ">";
            else cout << "<";
        }
        cout << "\n";
    }

    return 0;
}
