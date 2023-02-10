#include<bits/stdc++.h>
using namespace std;

int comp(char c)
{
    if(c == '+' || c == '-')
        return 1;
    else if(c == '*' || c == '/')
        return 2;
    else
        return 0;
}

int doMath(int num1, int num2, char sign)
{
    if(sign == '+')
        return num1+num2;
    else if(sign == '-')
        return num1-num2;
    else if(sign == '*')
        return num1*num2;
    else if(sign == '/')
        return num1/num2;
    else
        return 0;
}

int main()
{
    string st;
    cin >> st;
    stack<int>numbers;
    stack<char>operators;

    for(int i=0; i<st.size(); i++)
    {
        if(isdigit(st[i]))
        {
            int num = 0;
            while(i < st.size() && isdigit(st[i]))
            {
                num = num * 10 + (st[i] - '0');
                i++;
            }
            i--;
            numbers.push(num);
        }
        else
        {
            if(st[i] == '(')
                operators.push(st[i]);
            else if(st[i] == ')')
            {
                while(operators.top() != '(')
                {
                    int num2 = numbers.top();
                    numbers.pop();
                    int num1 = numbers.top();
                    numbers.pop();
                    char sign = operators.top();
                    operators.pop();
                    numbers.push(doMath(num1, num2, sign));
                }
                operators.pop();
            }
            else
            {
                while(operators.size() && comp(operators.top()) >= comp(st[i]))
                {
                    int num2 = numbers.top();
                    numbers.pop();
                    int num1 = numbers.top();
                    numbers.pop();
                    char sign = operators.top();
                    operators.pop();
                    numbers.push(doMath(num1, num2, sign));
                }
                operators.push(st[i]);
            }
        }
    }
    while(operators.size())
    {
        int num2 = numbers.top();
        numbers.pop();
        int num1 = numbers.top();
        numbers.pop();
        char sign = operators.top();
        operators.pop();
        numbers.push(doMath(num1, num2, sign));
    }
    cout << numbers.top() << "\n";

    return 0;
}
