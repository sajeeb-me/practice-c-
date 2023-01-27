#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node * nxt;
    node * prv;
};

class DoublyLinkedList
{
public:
    node *head;
    int sz;
    DoublyLinkedList()
    {
        head = NULL;
        sz = 0;
    }

    //Creates a new node with the given data and returns it O(1)
    node * CreateNewNode(int data)
    {
        node *newnode = new node;
        newnode->data = data;
        newnode->nxt = NULL;
        newnode->prv = NULL;
        return newnode;
    }

    //Inserts a node with given data at head O(1)
    void InsertAtHead(int data)
    {
        sz++;
        node *newnode = CreateNewNode(data);
        if(head == NULL)
        {
            head = newnode;
            return;
        }
        node *a = head;
        newnode->nxt = a;
        a->prv = newnode;
        head = newnode;
    }

    //Prints the linked list O(n)
    void Traverse()
    {
        node *a = head;
        while(a!=NULL)
        {
            cout<<a->data<<" ";
            a = a->nxt;
        }
        cout<<"\n";
    }

    void swap(int idx1, int idx2)
    {
        int idx_no1 = 0, idx_no2 = 0;
        node* a = head;
        while(idx1 != idx_no1)
        {
            a = a->nxt;
            idx_no1++;
        }
        node* b = head;
        while(idx2 != idx_no2)
        {
            b = b->nxt;
            idx_no2++;
        }
        int temp = a->data;
        a->data = b->data;
        b->data = temp;
    }
    void deleteZero()
    {
        node* a = head;
        int idx = 0;
        while(a != NULL)
        {
            if(a->data == 0)
            {
                if(a == head)
                {
                    head = a->nxt;
                    head->prv = NULL;
                    delete a;
                    a = head;
                }
                else if(a->nxt == NULL)
                {
                    a->prv->nxt = NULL;
                    delete a;
                    a = NULL;
                }
                else
                {
                    a->prv->nxt = a->nxt;
                    a->nxt->prv = a->prv;
                    node* temp = a->nxt;
                    delete a;
                    a = temp;
                }
            }
            else
                a = a->nxt;
        }
    }
};


int main()
{
    DoublyLinkedList dl;
    dl.InsertAtHead(7);
    dl.InsertAtHead(0);
    dl.InsertAtHead(4);
    dl.InsertAtHead(0);
    dl.InsertAtHead(2);
    dl.InsertAtHead(0);
    dl.InsertAtHead(3);
    dl.Traverse();
    dl.swap(1,4);
    dl.deleteZero();
    dl.Traverse();

    return 0;
}
