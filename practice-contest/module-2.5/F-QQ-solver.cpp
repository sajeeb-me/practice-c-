#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int result = (s[0]-48)*(s[2]-48);
    cout << result << "\n";

    return 0;
}
