#include<bits/stdc++.h>
using namespace std;

int main()
{
    string input;
    cin >> input;

    int chars[26] = {0};

    for(int i=0; i<input.length(); i++)
        chars[input[i] - 'a']++;

    int odd_count = 0;

    for(int i=0; i<26; i++)
        if(chars[i] % 2 != 0)
            odd_count++;

    if(odd_count <= 1) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
