#include<bits/stdc++.h>
using namespace std;

template<class T>
class node
{
public:
    T data;
    node* nxt;
};

template<class T>
class LinkedList
{
public:
    node<T>* head;
    int sz;

    LinkedList()
    {
        head = NULL;
        sz=0;
    }
    node<T>* CreateNewNode(T value)
    {
        node<T>* newnode = new node<T>;
        newnode->data = value;
        newnode->nxt = NULL;

        return newnode;
    }
    void InsertAtHead(T value)
    {
        sz++;
        node<T>* a = CreateNewNode(value);
        if(head == NULL)
        {
            head = a;
            return;
        }
        a->nxt = head;
        head = a;

    }

    int getSize()
    {
        return sz;
    }

    void DeleteAtHead()
    {
        if(head == NULL) return;
        sz--;
        node<T>* a = head;
        head = a->nxt;
        delete a;
    }

};

template<class T>
class Stack
{
public:
    LinkedList<T> l;

    Stack()
    {

    }

    void push(T val)
    {
        l.InsertAtHead(val);
    }
    void pop()
    {
        if(l.getSize() == 0)
        {
            cout << "Stack is empty!\n";
            return;
        }
        l.DeleteAtHead();
    }
    T top()
    {
        if(l.getSize() == 0)
        {
            cout << "Stack is empty!\n";
            T a;
            return a;
        }
        return l.head->data;
    }
};

int main()
{
    Stack<double> st;
    st.push(3.20);
    cout << st.top() << "\n";
    st.push(6.40);
    cout << st.top() << "\n";
    st.push(4.54);
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";

    return 0;
}
