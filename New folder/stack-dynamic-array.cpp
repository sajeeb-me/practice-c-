#include<bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int* a;
    int stack_size;
    int stack_cap;

    Stack()
    {
        stack_cap = 1;
        a = new int[stack_cap];
        stack_size = 0;
    }

    void increase_array()
    {
        int* tmp;
        tmp = new int[stack_cap*2];
        for(int i=0; i<stack_cap; i++)
            tmp[i] = a[i];
        swap(a, tmp);
        delete[] tmp;
        stack_cap *= 2;
    }

    void push(int val)
    {
        if(stack_size+1 >= stack_cap)
        {
            increase_array();
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
        a[stack_size-1] = 0;
        stack_size--;
    }

    int top()
    {
        if(stack_size == 0)
        {
            cout << "Stack is empty!\n";
            return -1;
        }
        return a[stack_size-1];
    }
};

int main()
{
    Stack st;
    st.push(3);
    cout << st.top() << "\n";
    st.push(5);
    cout << st.top() << "\n";
    st.push(7);
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";

    return 0;
}
