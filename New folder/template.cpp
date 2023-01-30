#include<bits/stdc++.h>
using namespace std;

template<class T>
class Stack
{
public:
    T* a;
    int stack_size;
    int stack_cap;

    Stack()
    {
        stack_cap = 1;
        a = new T[stack_cap];
        stack_size = 0;
    }

    void increase_array()
    {
        T* tmp;
        tmp = new T[stack_cap*2];
        for(int i=0; i<stack_cap; i++)
            tmp[i] = a[i];
        swap(a, tmp);
        delete[] tmp;
        stack_cap *= 2;
    }

    void push(T val)
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
//        a[stack_size-1] = 0;
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
    st.push(3.5);
    cout << st.top() << "\n";
    st.push(5.6);
    cout << st.top() << "\n";
    st.push(7.2);
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";

    cout << "\n\n";

    Stack<string> st2;
    st2.push("ami");
    cout << st2.top() << "\n";
    st2.push("go");
    cout << st2.top() << "\n";
    st2.push("dear");
    cout << st2.top() << "\n";
    st2.pop();
    cout << st2.top() << "\n";
    st2.pop();
    cout << st2.top() << "\n";
    st2.pop();
    cout << st2.top() << "\n";

    return 0;
}
