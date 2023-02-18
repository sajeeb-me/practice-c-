#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int id, value;
    node* Left;
    node* Right;
    node* parent;
};

class BinaryTree
{
public:
    node* root;

    BinaryTree()
    {
        root = NULL;
    }
    node* CreateNewNode(int id, int value)
    {
        node* newNode = new node;
        newNode->id = id;
        newNode->value = value;
        newNode->Left = NULL;
        newNode->Right = NULL;
        newNode->parent = NULL;
        return newNode;
    }
    void build_binary_tree()
    {
        node* allnode[6];
        for(int i=0; i<6; i++)
            allnode[i] = CreateNewNode(i, i);

        root = allnode[0];

        allnode[0]->Left = allnode[1];
        allnode[0]->Right = allnode[2];

        allnode[1]->Left = allnode[5];
        allnode[1]->parent = allnode[0];

        allnode[2]->Left = allnode[3];
        allnode[2]->Right = allnode[4];
        allnode[2]->parent = allnode[0];

        allnode[5]->parent = allnode[1];

        allnode[3]->parent = allnode[2];
        allnode[4]->parent = allnode[2];
    }
    void Insertaion(int id, int value)
    {
        node* newNode = CreateNewNode(id, value);
        if(root == NULL)
        {
            root = newNode;
            return;
        }
        queue<node*>q;
        q.push(root);

        while(!q.empty())
        {
            node* a = q.front();
            q.pop();
            if(a->Left != NULL)
                q.push(a->Left);
            else
            {
                a->Left = newNode;
                newNode->parent = a;
                return;
            }
            if(a->Right != NULL)
                q.push(a->Right);
            else
            {
                a->Right = newNode;
                newNode->parent = a;
                return;
            }
        }
    }
    void Search(node* a, int value)
    {
        if(a == NULL)
            return;
        if(a->value == value)
            cout << a->id << " ";
        Search(a->Left, value);
        Search(a->Right, value);
    }
    int height(node* a)
    {
        if(a == NULL)
            return 0;
        int leftHeight = height(a->Left);
        int rightHeight = height(a->Right);
        return max(leftHeight, rightHeight)+1;
    }
//  BFS
    void BFS()
    {
        queue<node*>q;
        q.push(root);

        while(!q.empty())
        {
            node* a = q.front();
            q.pop();
            int p = -1, l = -1, r = -1;
            if(a->Left != NULL)
            {
                l = a->Left->id;
                q.push(a->Left);
            }
            if(a->Right != NULL)
            {
                r = a->Right->id;
                q.push(a->Right);
            }
            if(a->parent != NULL)
                p = a->parent->id;
            cout << "Node id= " << a->id << " Left child = " << l << " Right child = " << r << " Parent id = " << p << "\n";
        }
    }
//  DFS
    void Inorder(node* a)
    {
        if(a == NULL)
            return;
        Inorder(a->Left);
        cout << a->id << " ";
        Inorder(a->Right);
    }
    void Preorder(node* a)
    {
        if(a == NULL)
            return;
        cout << a->id << " ";
        Preorder(a->Left);
        Preorder(a->Right);
    }
    void Postorder(node* a)
    {
        if(a == NULL)
            return;
        Postorder(a->Left);
        Postorder(a->Right);
        cout << a->id << " ";
    }
    bool isPerfect(node* a)
    {
        if(a == NULL)
            return true;
        int leftHeight = height(a->Left);
        int rightHeight = height(a->Right);
        if(leftHeight != rightHeight)
            return false;

        return isPerfect(a->Left) && isPerfect(a->Right);
    }

};

int main()
{
    BinaryTree bt;
    bt.Insertaion(0, 5);
    bt.Insertaion(1, 10);
    bt.Insertaion(2, 10);
    bt.Insertaion(3, 9);
    bt.Insertaion(4, 8);
    bt.Insertaion(5, 5);
    bt.Insertaion(6, 7);
    bt.Insertaion(7, 7);
    bt.Insertaion(8, 7);

    cout << "Height: " << bt.height(bt.root) << "\n";
    cout << "Is perfect: " << (bt.isPerfect(bt.root) ? "Yes\n" : "No\n" );

//    bt.build_binary_tree();
//    bt.BFS();
//    bt.Inorder(bt.root);
//    bt.Preorder(bt.root);
    bt.Postorder(bt.root);

//    bt.Search(bt.root, 8);

    return 0;
}
