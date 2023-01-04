#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int match = 1, result = 1;
    for(int i=1; i<s.size(); i++)
    {
        if(s[i]==s[i-1])
        {
            match++;
            if(match>result)
                result=match;
        }
        else
            match = 1;
    }

    cout << result << "\n";

    return 0;
}
