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
        swap(tmp, a);
        delete[] tmp;
        stack_cap *= 2;

    }

    void decrease_size()
    {
        T* tmp;
        tmp = new T[stack_cap/2];
        for(int i=0; i<stack_cap; i++)
            tmp[i] = a[i];
        swap(tmp, a);
        delete[] tmp;
        stack_cap /= 2;
    }

    void push(T val)
    {
        if(stack_size+1 >= stack_cap)
            increase_array();
        if(stack_size < stack_cap/2)
            decrease_size();
        stack_size++;
        a[stack_size-1] = val;
    }
    void pop()
    {
        if(stack_size < stack_cap/2)
            decrease_size();
        if(stack_size == 0)
        {
            cout << "Stack is empty!\n";
            return;
        }
        stack_size--;
    }
    T top()
    {
        if(stack_size < stack_cap/2)
            decrease_size();
        if(stack_size == 0)
        {
            cout << "Stack is empty!\n";
            T a;
            return a;
        }
        return a[stack_size-1];
    }
    int getSize()
    {
        return stack_size;
    }
};

int main()
{
//    Stack<double> st;
//    st.push(8.20);
//    cout << st.top() << "\n";
//    st.push(26.40);
//    cout << st.top() << "\n";
//    st.push(4.54);
//    cout << st.top() << "\n";
//    st.pop();
//    cout << st.top() << "\n";
//    st.pop();
//    cout << st.top() << "\n";
//    st.pop();
//    cout << st.top() << "\n";


//    Sort Stack
    Stack<int> st;
    st.push(8);
    st.push(2);
    st.push(4);

    Stack<int>tmp;
    while(st.getSize() > 0)
    {
        int t = st.top();
        st.pop();
        while(tmp.getSize() > 0)
        {
            if(tmp.top() < t)
                break;
            st.push(tmp.top());
            tmp.pop();
        }
        tmp.push(t);
    }

    swap(tmp, st);
    while(st.getSize() > 0)
    {
        cout << st.top() << "\n";
        st.pop();
    }

//    reverse stack
//    Stack<int> st;
//    st.push(8);
//    st.push(2);
//    st.push(4);
//
//    Stack<int>tmp;
//    while(st.getSize() > 0)
//    {
//        tmp.push(st.top());
//        st.pop();
//    }
//
//    swap(tmp, st);
//    while(st.getSize() > 0)
//    {
//        cout << st.top() << "\n";
//        st.pop();
//    }

    return 0;
}
