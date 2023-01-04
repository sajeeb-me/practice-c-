#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int l = s.size();

    for(int i=0; i<l; i++)
    {
        if(i%2==0)
        {
            if(s[i]+1 > 122)
                cout << static_cast<char>(s[i]-25);
            else
                cout << static_cast<char>(s[i]+1);
        }
        else
            cout << s[i];
    }

    return 0;
}
