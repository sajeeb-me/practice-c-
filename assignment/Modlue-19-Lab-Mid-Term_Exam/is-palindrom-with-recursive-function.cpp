#include<bits/stdc++.h>
using namespace std;

bool checkPalindrom(string s, int start, int endd)
{
    if(start >= endd)
        return true;

    if(s[start] != s[endd])
        return false;

    return checkPalindrom(s, start+1, endd-1);
}

int main()
{
    string s;
    cin >> s;
    int sz = s.length();
    if(checkPalindrom(s, 0, sz-1))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
