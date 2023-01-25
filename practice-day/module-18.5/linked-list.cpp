#include<bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node * nxt;
};

class LinkedList
{
public:
    node * head;
    int sz;
    LinkedList()
    {
        head = NULL;
        sz=0;
    }

    //Creates a new node with data = value and nxt= NULL
    node* CreateNewNode(int value)
    {
        node *newnode = new node;
        newnode->data = value;
        newnode->nxt = NULL;
        return newnode;
    }

    // Insert new value at Head
    void InsertAtHead(int value)
    {
        sz++;
        node *a = CreateNewNode(value);
        if(head == NULL)
        {
            head = a;
            return;
        }
        //If head is not NULL
        a->nxt = head;
        head = a;
    }

    //Prints the linked list
    void Traverse()
    {
        node* a = head;
        while(a!= NULL)
        {
            cout<<a->data<<" ";
            a = a->nxt;
        }
        cout<<"\n";
    }

    //Search for a single value
    int SearchDistinctValue(int value)
    {
        node* a = head;
        int index = 0;
        while(a!= NULL)
        {
            if(a->data==value)
            {
                return index;
            }
            a = a->nxt;
            index++;
        }
        return -1;
    }

    //Search all possible occurrence
    void SearchAllValue(int value)
    {
        node* a = head;
        int index = 0;
        while(a!= NULL)
        {
            if(a->data==value)
            {
                cout<<value<<" is found at index "<<index<<"\n";
            }
            a = a->nxt;
            index++;
        }
    }

    //Returns number of elements in the linked list
    int getSize()
    {
        //O(1)
        return sz;


        //O(size of linked list) = O(n)
//        int sz = 0;
//        node *a = head;
//        while(a!=NULL)
//        {
//            sz++;
//            a = a->nxt;
//        }
//        return sz;
    }

    //Insert a value at the given index
    void InsertAtAnyIndex(int index, int value)
    {
        if(index <0 || index > sz)
        {
            return;
        }
        if(index==0)
        {
            InsertAtHead(value);
            return;
        }
        sz++;
        node *a = head;
        int cur_index = 0;
        while(cur_index!=index-1)
        {
            a = a->nxt;
            cur_index++;
        }
        node *newnode = CreateNewNode(value);
        newnode->nxt = a->nxt;
        a->nxt = newnode;
    }

    //Delete the first element of a linked list
    void DeleteAtHead()
    {
        if(head == NULL)
        {
            return;
        }
        sz--;
        node *a = head;
        head = a->nxt;
        delete a;
    }

    //Delete the value at the given index
    void DeleteAnyIndex(int index)
    {
        if(index <0 || index > sz-1)
        {
            return;
        }
        if(index==0)
        {
            DeleteAtHead();
            return;
        }
        sz--;
        node *a = head;
        int cur_index = 0;
        while(cur_index != index-1)
        {
            a = a->nxt;
            cur_index++;
        }
        node *b = a->nxt;
        a->nxt = b->nxt;
        delete b;
    }

    void InsertAfterValue(int value, int data)
    {
        node *a = head;
        while(a != NULL)
        {
            if(a->data == value)
            {
                break;
            }
            a = a->nxt;
        }
        if(a== NULL)
        {
            cout<<value<<" doesn't exist in linked-list.\n";
            return;
        }
        sz++;
        node *newnode = CreateNewNode(data);
        newnode->nxt = a->nxt;
        a->nxt = newnode;
    }

    //Print the Reverse Order from node a to last
    void ReversePrint2(node *a)
    {
        if(a==NULL)
        {
            return;
        }
        ReversePrint2(a->nxt);
        cout<<a->data<<" ";
    }
    void ReversePrint()
    {
        ReversePrint2(head);
        cout<<"\n";
    }

    int getValue(int index)
    {
        if(index > sz-1)
            return -1;
        node* a = head;
        int idx = 0;
        while(idx != index)
        {
            a = a->nxt;
            idx++;
        }
        return a->data;
    }

    void deleteZero()
    {
        node *current = head;
        node *prev = NULL;
        while (current != NULL)
        {
            if (current->data == 0)
            {
                sz--;
                if (prev == NULL)
                {
                    head = current->nxt;
                    current = head;
                }
                else
                {
                    prev->nxt = current->nxt;
                    current = prev->nxt;
                }
            }
            else
            {
                prev = current;
                current = current->nxt;
            }
        }
    }

    int getOddIndexSum()
    {
        node* a = head;
        int idx = 0, sum = 0;
        while(a != NULL)
        {
            if(idx % 2 != 0)
                sum += a->data;
            a = a->nxt;
            idx++;
        }
        return sum;
    }

    bool hasDuplicate()
    {
        unordered_set<int> set;
        node* current = head;
        while (current != NULL)
        {
            if (set.find(current->data) != set.end())
            {
                return true;
            }
            set.insert(current->data);
            current = current->nxt;
        }
        return false;
    }

};

int main()
{
    LinkedList l;
    l.InsertAtHead(5);
    l.InsertAtHead(4);
    l.InsertAtHead(0);
    l.InsertAtHead(2);
    l.InsertAtHead(0);
    l.InsertAtHead(1);
    l.InsertAtHead(3);
    l.Traverse();

//    cout << l.getValue(0) << "\n";
//    l.deleteZero();
//    l.Traverse();

//    cout << l.getOddIndexSum() << "\n";
    cout << l.hasDuplicate() << "\n";


    return 0;
}
