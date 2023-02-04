#include <bits/stdc++.h>
using namespace std;

bool checkBalanced(string s)
{
    stack<char> stk;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            stk.push(s[i]);

        else
        {
            if (stk.empty())
                return false;

            if (s[i] == ')' && stk.top() == '(' || s[i] == ']' && stk.top() == '[' || s[i] == '}' && stk.top() == '{')
                stk.pop();
            else
                return false;
        }
    }
    return stk.empty();
}

int main()
{
    string s = "(([][]{()}))";
    cout << (checkBalanced(s) ? "Balanced" : "Not Balanced");
    return 0;
}
