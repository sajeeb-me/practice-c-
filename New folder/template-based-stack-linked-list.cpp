#include<bits/stdc++.h>
using namespace std;

template<class T>
class node
{
public:
    T data;
    node* nxt;
    node* prv;
};

template<class T>
class DublyLinkedList
{
public:
    node<T>* head;
    int sz;

    DublyLinkedList()
    {
        head = NULL;
        sz = 0;
    }

    node<T>* CreateNewNode(T data)
    {
        node<T>* newNode = new node<T>;
        newNode->data = data;
        newNode->nxt = NULL;
        newNode->prv = NULL;
        return newNode;
    }

    void InsertAtHead(T data)
    {
        sz++;
        node<T>* newNode = CreateNewNode(data);
        if(head == NULL)
        {
            head = newNode;
            return;
        }
        node<T>* a = head;
        newNode->nxt = a;
        a->prv = newNode;
        head = newNode;
    }

    int getSize()
    {
        return sz;
    }

    void DeleteAtHead()
    {
        if(head == NULL)
            return;
        node<T>* a = head;
        node<T>* b = head->nxt;
        delete a;
        if(b != NULL)
            b->prv = NULL;
        head = b;
        sz--;
    }
};

template<class T>
class Stack
{
public:
    DublyLinkedList<T> dl;

    Stack()
    {

    }

    T top()
    {
        if(dl.getSize() == 0)
        {
            cout << "Stack is empty!\n";
            T a;
            return a;
        }
        return dl.head->data;
    }

    void push(T val)
    {
        dl.InsertAtHead(val);
    }

    void pop()
    {
        if(dl.getSize() == 0)
        {
            cout << "Stack is empty!\n";
            return;
        }

        dl.DeleteAtHead();
    }

    int getSize()
    {
        return dl.getSize();
    }
};

int main()
{
    Stack<int> st;
    st.push(5);
    st.push(8);
    st.push(3);
    st.push(4);
    st.push(9);

    // sort
    Stack<int> tmp;
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



// reverse stack
//    Stack<int>tmp;
//    while(st.getSize() > 0)
//    {
//        tmp.push(st.top());
//        st.pop();
//

    swap (st, tmp);
    while(st.getSize() > 0)
    {
        cout << st.top()<< "\n";
        st.pop();
    }

//    Stack<double> st;
//    st.push(3.5);
//    cout << st.top() << "\n";
//    st.push(5.6);
//    cout << st.top() << "\n";
//    st.push(7.2);
//    cout << st.top() << "\n";
//    st.pop();
//    cout << st.top() << "\n";
//    st.pop();
//    cout << st.top() << "\n";
//    st.pop();
//    cout << st.top() << "\n";


//    cout << "\n\n";

//    Stack<string> st2;
//    st2.push("ami");
//    cout << st2.top() << "\n";
//    st2.push("go");
//    cout << st2.top() << "\n";
//    st2.push("dear");
//    cout << st2.top() << "\n";
//    st2.pop();
//    cout << st2.top() << "\n";
//    st2.pop();
//    cout << st2.top() << "\n";
//    st2.pop();
//    cout << st2.top() << "\n";

    return 0;
}
