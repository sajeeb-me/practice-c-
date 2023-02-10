#include<bits/stdc++.h>
using namespace std;

template<class T>
class Node
{
public:
    T data;
    Node* nxt;
};

template<class T>
class Stack
{
public:
    Node<T>* head;
    int sz;

    Stack()
    {
        head = NULL;
        sz = 0;
    }
    Node<T>* CreateNewNode(T value)
    {
        Node<T>* newNode = new Node<T>;
        newNode->data = value;
        newNode->nxt = NULL;
        return newNode;
    }
    void push(T value)
    {
        sz++;
        Node<T>* newNode = CreateNewNode(value);
        if(head == NULL)
        {
            head = newNode;
            return;
        }
        newNode->nxt = head;
        head = newNode;
    }
    void pop()
    {
        if(sz == 0)
        {
            cout << "empty!\n";
            return;
        }
        sz--;
        Node<T>* a = head;
        head = head->nxt;
        delete a;
    }
    T top()
    {
        if(sz == 0)
        {
            cout << "empty!\n";
            T a;
            return a;
        }
        return head->data;
    }
};

int main()
{
    Stack<char> s;
    s.push('a');
    s.push('b');
    s.push('c');

    cout << s.top() << "\n";
    s.pop();
    cout << s.top() << "\n";
    s.pop();
    cout << s.top() << "\n";
    s.pop();

    return 0;
}
