#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int value;
    node* Right;
    node* Left;
};

class BST
{
public:
    node* root;

    BST()
    {
        root = NULL;
    }
    node* CreateNewNode(int value)
    {
        node* newNode = new node;
        newNode->value = value;
        newNode->Right = NULL;
        newNode->Left = NULL;
        return newNode;
    }
    void BFS()
    {
        queue<node*>q;
        q.push(root);
        while(!q.empty())
        {
            node* a = q.front();
            q.pop();
            int l = -1, r = -1;
            if(a->Left != NULL)
            {
                l = a->Left->value;
                q.push(a->Left);
            }
            if(a->Right != NULL)
            {
                r = a->Right->value;
                q.push(a->Right);
            }
            cout << "Node value: " << a->value << " Left child: " << l << " Right child: " << r << "\n";
        }
    }
    void Insert(int value)
    {
        node* newNode = CreateNewNode(value);
        if(root == NULL)
        {
            root = newNode;
            return;
        }
        node* cur = root;
        node* prv = NULL;

        while(cur != NULL)
        {
            if(newNode->value > cur->value)
            {
                prv = cur;
                cur = cur->Right;
            }
            else
            {
                prv = cur;
                cur = cur->Left;
            }
        }
        if(newNode->value > prv->value)
            prv->Right = newNode;
        else
            prv->Left = newNode;
    }
    bool Search(int value)
    {
        node* cur = root;
        while(cur != NULL)
        {
            if(value > cur->value)
                cur = cur->Right;
            else if(value < cur->value)
                cur = cur->Left;
            else
                return true;
        }
        return false;
    }
    void Delete(int value)
    {
        node* cur = root;
        node* prv = NULL;
        while(cur != NULL)
        {
            if(value > cur->value)
            {
                prv = cur;
                cur = cur->Right;
            }
            else if(value < cur->value)
            {
                prv = cur;
                cur = cur->Left;
            }
            else
                break;
        }
        if(cur == NULL)
        {
            cout << "Value is not present!\n";
            return;
        }
        // Case 1: node has no child
        if(cur->Left == NULL && cur->Right == NULL)
        {
            if(prv->Left->value == cur->value)
                prv->Left = NULL;
            else
                prv->Right = NULL;
            delete cur;
            return;
        }
        // Case 2: node has one child
        if(cur->Left == NULL && cur->Right != NULL)
        {
            if(prv->Left->value == cur->value)
                prv->Left = cur->Right;
            else
                prv->Right = cur->Right;
            delete cur;
            return;
        }
        if(cur->Left != NULL && cur->Right == NULL)
        {
            if(prv->Left->value == cur->value)
                prv->Left = cur->Left;
            else
                prv->Right = cur->Left;
            delete cur;
            return;
        }
        // Case 3: node has two child
        node* tmp = cur->Right;
        while(tmp->Left != NULL)
            tmp = tmp->Left;
        int saved = tmp->value;
        Delete(saved);
        cur->value = saved;
    }
    int Minimum()
    {
        node* a = root;
        while(a->Left != NULL)
            a = a->Left;
        return a->value;
    }
    int Maximum()
    {
        node* a = root;
        while(a->Right != NULL)
            a = a->Right;
        return a->value;
    }
    bool isValidBinaryTree(node* a)
    {
//        node* leftHigh = a->Left;
//        while(leftHigh->Right != NULL)
//            leftHigh = leftHigh->Right;
//        int leftHightValue = leftHigh->value;
//        node* rightLow = a->Right;
//        while(rightLow->Left != NULL)
//            rightLow = rightLow->Left;
//        int rightLowValue = rightLow->value;
//
//        cout << "left high value: " << leftHightValue << " , right low value: " << rightLowValue << "\n";

        if(a == NULL)
            return true;
        if((a->Left != NULL && a->Left->value > a->value) || (a->Right != NULL && a->Right->value <= a->value))
            return false;

        return isValidBinaryTree(a->Left) && isValidBinaryTree(a->Right);
    }
};

int main()
{
    BST bst;
    bst.Insert(5);
    bst.Insert(8);
    bst.Insert(3);
    bst.Insert(4);
    bst.Insert(7);
    bst.Insert(9);
    bst.Insert(10);
    bst.Insert(2);

//    bst.Delete(5);
    bst.BFS();
    cout << (bst.Search(9) ? "Exist!\n" : "Not exist!\n");
    cout << "Minimum value: " << bst.Minimum() << "\n";
    cout << "Maximum value: " << bst.Maximum() << "\n";
    cout << (bst.isValidBinaryTree(bst.root) ? "Valid tree!\n" : "Not valid!\n");
    return 0;
}
