#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node* nxt;
    Node* prv;
};

class DublyLinkedList
{
public:
    Node* head;
    int sz;

    DublyLinkedList()
    {
        head = NULL;
        sz = 0;
    }

    Node* createNewNode(int value)
    {
        Node* newNode = new Node;
        newNode->value = value;
        newNode->nxt = NULL;
        newNode->prv = NULL;
        return newNode;
    }

    void InsertAtHead(int value)
    {
        sz++;
        Node* newNode = createNewNode(value);
        if(head == NULL)
        {
            head = newNode;
            return;
        }
        newNode->nxt = head;
        head->prv = newNode;
        head = newNode;
    }

    void Traverse()
    {
        Node* a = head;
        while(a != NULL)
        {
            cout << a->value << " ";
            a = a->nxt;
        }
        cout << "\n";
    }

    int GetSize()
    {
        return sz;
    }

    void RemoveLastElement()
    {
        sz--;
        Node* a = head;
        Node* b;
        while (a->nxt != NULL)
        {
            b = a;
            a = a->nxt;
        }
        b->nxt = NULL;
        delete a;
    }

    void SearchIthElement(int index)
    {
        Node* a = head;
        int idx_value = 0;
        while(idx_value != index)
        {
            a = a->nxt;
            idx_value++;
        }
        cout << a->value << "\n";
    }

    string SearchValue(int value)
    {
        Node* a = head;
        while(a != NULL)
        {
            if(a->value == value)
                return "True";
            a = a->nxt;
        }
        return "False";
    }

    void Reverse()
    {
        if(head == NULL)
        {
            return;
        }
        Node* a = head;
        int idx_size = 0;
        while(idx_size != sz-1)
        {
            a = a->nxt;
            idx_size++;
        }
        Node* b = head;
        while(b != NULL)
        {
            swap(b->nxt, b->prv);
            b = b->prv;
        }
        head = a;
    }

    void InsertAnElement(int index, int value)
    {
        if(index > sz || index < 0)
            return;

        sz++;
        if(index == 0)
        {
            InsertAtHead(value);
            return;
        }
        Node* a = head;
        int idx_no = 0;
        while(idx_no != index-1)
        {
            a = a->nxt;
            idx_no++;
        }
        Node* newNode = createNewNode(value);
        Node* b = a->nxt;
        a->nxt = newNode;
        b->prv = newNode;
        newNode->nxt = b;
        newNode->prv = a;
    }

    void DeleteAnElement(int value)
    {
        Node* a = head;
        Node* el = head;
        while(a != NULL)
        {
            if(a->value == value)
            {
                el = a;
                break;
            }
            a = a->nxt;
        }
        if(el->value != value)
            return;

        sz--;
        Node* b = el->prv;
        Node* c = el->nxt;

        if(b != NULL)
            b->nxt = c;
        else
            head = c;

        if(c != NULL)
            c->prv = b;
        delete el;
    }

    string IsPalindrome()
    {
        Node* a = head;
        while(a->nxt != NULL)
            a = a->nxt;
        Node* b = head;

        for(int i=0; i<sz/2; i++)
        {
//            cout << "a: " << a->value << " b: " << b->value << "\n";
            if(b->value != a->value)
                return "False";

            b = b->nxt;
            a = a->prv;
        }
        return "True";
    }

};

int main()
{
    DublyLinkedList dl;

    dl.InsertAtHead(1);
    dl.InsertAtHead(2);
//    dl.InsertAtHead(3);
    dl.InsertAtHead(3);
    dl.InsertAtHead(2);
    dl.InsertAtHead(1);

//    dl.InsertAtHead(0);
    dl.Traverse();

//    dl.InsertAnElement(2,100);
//    dl.Traverse();

//    dl.DeleteAnElement(100);
//    dl.Traverse();

    cout << dl.IsPalindrome() << "\n";


//    dl.RemoveLastElement();
//    dl.Traverse();

//    dl.Reverse();
//    dl.Traverse();

//    dl.SearchIthElement(2);
//    cout << dl.SearchValue(4) << "\n";

    cout << "Size: " << dl.GetSize() << "\n";

    return 0;
}
