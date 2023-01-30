#include<bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 10;
template<class T>
class Stack
{
public:
    T a[MAX_SIZE];
    int stack_size;

    Stack()
    {
        stack_size = 0;
    }

    void push(T val)
    {
        if(stack_size+1 >= MAX_SIZE)
        {
            cout << "Stack size is full!\n";
            return;
        }
        stack_size++;
        a[stack_size-1] = val;
    }

    void pop()
    {
        if(stack_size == 0)
        {
            cout << "Stack is empty!\n";
            return;
        }
        stack_size--;
    }

    T top()
    {
        if(stack_size == 0)
        {
            cout << "Stack is empty!\n";
            T a;
            return a;
        }
        return a[stack_size-1];
    }
};

int main()
{
    Stack<double> st;
    st.push(5.20);
    cout << st.top() << "\n";
    st.push(3.40);
    cout << st.top() << "\n";
    st.push(7.54);
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";

    return 0;
}
