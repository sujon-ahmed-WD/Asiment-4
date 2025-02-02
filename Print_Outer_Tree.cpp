#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *input_tree()
{
    int val;
    cin >> val;
    Node *root;
    if (val == -1)
        root = NULL;
    else
        root = new Node(val);
    queue<Node *> q;
    if (root)
        q.push(root);

    while (!q.empty())
    {
        Node *prant = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        Node *myleft, *myright;
        if (l == -1)
            myleft = NULL;
        else
            myleft = new Node(l);
        if (r == -1)
            myright = NULL;
        else
            myright = new Node(r);

        prant->left = myleft;
        prant->right = myright;

        if (prant->left)
            q.push(prant->left);
        if (prant->right)
            q.push(prant->right);
    }
    return root;
}
void left_Boundary(Node *root, vector<int> &LB)
{
    while (root != NULL)
    {
        LB.push_back(root->val);
        if (root->left != NULL)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
}
void right_Boundary(Node *root, vector<int> &RB)
{
    while (root != NULL)
    {
        RB.push_back(root->val);
        if (root->right != NULL)
            root = root->right;
        else
            root = root->left;
    }
}
int main()
{
    Node *root = input_tree();

    vector<int> LB_node, RB_node;
    left_Boundary(root->left, LB_node);

    for (auto it = LB_node.rbegin(); it != LB_node.rend(); it++)
    {
        cout << *it << " ";
    }
    cout << root->val << " ";
    right_Boundary(root->right, RB_node);
    for (auto it : RB_node)
    {
        cout << it << " ";
    }

    return 0;
}