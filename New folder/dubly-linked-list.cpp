#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node* nxt;
    node* prv;
};

class DublyLinkedList
{
public:
    node* head;
    int sz;

    DublyLinkedList()
    {
        head = NULL;
        sz = 0;
    }

    node* CreateNewNode(int data)
    {
        node* newNode = new node;
        newNode->data = data;
        newNode->nxt = NULL;
        newNode->prv = NULL;
        return newNode;
    }

    void InsertAtHead(int data)
    {
        sz++;
        node* newNode = CreateNewNode(data);
        if(head == NULL)
        {
            head = newNode;
            return;
        }
        node* a = head;
        newNode->nxt = a;
        a->prv = newNode;
        head = newNode;
    }

    void Traverse()
    {
        node* a = head;
        while(a != NULL)
        {
            cout << a->data << " ";
            a = a->nxt;
        }
        cout << "\n";
    }

    int getSize()
    {
        return sz;
    }

    void Insert(int index, int data)
    {
        if(index > sz || index < 0)
        {
            return;
        }
        sz++;
        if(index == 0)
        {
            InsertAtHead(data);
            return;
        }
        node* a = head;
        int cur_index = 0;
        while(cur_index != index-1)
        {
            a = a->nxt;
            cur_index++;
        }
        node* newNode = CreateNewNode(data);
        newNode->nxt = a->nxt;
        newNode->prv = a;
        node* b = a->nxt;
        b->prv = newNode;
        a->nxt = newNode;
    }

    void Delete(int index)
    {
        if(index >= sz || index < 0)
        {
            cout << index << " doesn't exist!\n";
            return;
        }
        sz--;
        node* a = head;
        int cur_index = 0;
        while (cur_index != index)
        {
            a = a->nxt;
            cur_index++;
        }
        node* b = a->prv;
        node* c = a->nxt;
        if(b != NULL)
            b->nxt = c;

        if(c != NULL)
            c->prv = b;

        delete a;
        if(index == 0)
            head = c;
    }

    void Reverse()
    {
        if(head == NULL)
            return;

        node* a = head;
        int cur_index = 0;
        while (cur_index != sz-1)
        {
            a = a->nxt;
            cur_index++;
        }

//        cout << a->prv << " " << a->data << " " << a->nxt << "\n";

        node* b = head;
        while(b != NULL)
        {
            swap(b->nxt, b->prv);
            b = b->prv;
        }
//        cout << a->prv << " " << a->data << " " << a->nxt << "\n";
        head = a;
    }

};

int main()
{
    DublyLinkedList dl;

    dl.InsertAtHead(10);
    dl.InsertAtHead(5);
    dl.InsertAtHead(1);
    dl.InsertAtHead(3);
    dl.InsertAtHead(12);
    dl.InsertAtHead(8);
    dl.InsertAtHead(6);

    dl.Traverse();

    dl.Reverse();
    dl.Traverse();

//    dl.Insert(2, 100);
//    dl.Traverse();
//
//    dl.Delete(1);
//    dl.Traverse();

    cout << "size: " << dl.getSize() << "\n";

    return 0;
}
