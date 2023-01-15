#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node* nxt;
};

class LinkedList
{
public:
    node* head;
    int sz;

    LinkedList()
    {
        head = NULL;
        sz=0;
    }
    node* CreateNewNode(int value)
    {
        node* newnode = new node;
        newnode->data = value;
        newnode->nxt = NULL;

        return newnode;
    }
    void InsertAtHead(int value)
    {
        sz++;
        node* a = CreateNewNode(value);
        if(head == NULL)
        {
            head = a;
            return;
        }
        a->nxt = head;
        head = a;

    }
    void Traverse()
    {
        node* a = head;
        while(a != NULL)
        {
            cout << a->data << " ";
            a=a->nxt;
        }
        cout << "\n";
    }
    int SearchDistinctValue(int value)
    {
        node* a = head;
        int index = 0;
        while(a != NULL)
        {
            if(a->data == value)
                return index;
            a=a->nxt;
            index++;
        }
        return -1;
    }
    void SearchAllValue(int value)
    {
        node* a = head;
        int index = 0;
        while(a != NULL)
        {
            if(a->data == value)
                cout << value << " is found at index " << index << "\n";
            a=a->nxt;
            index++;
        }
    }

    int getSize()
    {
        return sz;
    }

    void InsertAtAnyIndex(int index, int value)
    {
        if(index < 0 || index > sz)
        {
            cout << "index " << index << " is invelied!\n";
            return;
        }
        if(index == 0)
        {
            InsertAtHead(value);
            return;
        }
        sz++;
        node* a = head;
        int cur_index = 0;
        while(cur_index != index-1)
        {
            a=a->nxt;
            cur_index++;
        }
        node* newNode = CreateNewNode(value);
        newNode->nxt = a->nxt;
        a->nxt = newNode;
    }

    void DeleteAtHead()
    {
        if(head == NULL) return;
        sz--;
        node* a = head;
        head = a->nxt;
        delete a;
    }

    void DeleteAtAnyIndex(int index)
    {
        if(index < 0 || index > sz-1)
        {
            cout << "index " << index << " is invelied!\n";
            return;
        }
        if(index == 0)
        {
            DeleteAtHead();
            return;
        }
        sz--;
        node* a = head;
        int cur_index = 0;
        while(cur_index != index-1)
        {
            a=a->nxt;
            cur_index++;
        }
        node* b = a->nxt;
        a->nxt = b->nxt;
        delete b;
    }

};

int main()
{
    LinkedList l;

    l.InsertAtHead(10);
    l.InsertAtHead(30);    l.InsertAtHead(20);
    l.InsertAtHead(30);
    l.Traverse();

    l.InsertAtAnyIndex(1, 100);
    l.Traverse();
    l.InsertAtAnyIndex(5, 500);
    l.Traverse();
    cout << "Size: " << l.getSize() << "\n";

//    l.InsertAtAnyIndex(10, 800);
//    l.Traverse();
//    cout << "Size: " << l.getSize() << "\n";

    l.DeleteAtHead();
    l.Traverse();
    cout << "Size: " << l.getSize() << "\n";

    l.DeleteAtAnyIndex(2);
    l.Traverse();
    cout << "Size: " << l.getSize() << "\n";


    return 0;
}
