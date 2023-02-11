#include<bits/stdc++.h>
using namespace std;

bool isPalindrom(string st)
{
    deque<char> ch;
    for(char c : st)
        ch.push_back(c);

    while(ch.size() > 1)
    {
        if(ch.front() != ch.back())
            return false;
        ch.pop_back();
        ch.pop_front();
    }
    return true;
}

int main()
{
    string s;
    cin >> s;
    cout << (isPalindrom(s) ? "Yes" : "No");

    return 0;
}
