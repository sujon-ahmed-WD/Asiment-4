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
        Node *mylift, *myright;
        if (l == -1)
            mylift = NULL;
        else
            mylift = new Node(l);
        if (r == -1)
            myright = NULL;
        else
            myright = new Node(r);
        prant->left = mylift;
        prant->right = myright;

        if (prant->left)
            q.push(prant->left);
        if (prant->right)
            q.push(prant->right);
    }
    return root;
}

int max_hight(Node *root)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    int l = max_hight(root->left);
    int r = max_hight(root->right);
    return max(l, r) + 1;
}

int count_node(Node *root)
{
    if (root == NULL)
        return 0;

    int l = count_node(root->left);
    int r = count_node(root->right);

    return l + r + 1;
}

int main()
{
    Node *root = input_tree();
    int h = max_hight(root);
    int co = count_node(root);

    if (root == NULL)
    {
        cout << "YES";
        return 0;
    }

    int result = pow(2, h) - 1;

    if (result == co)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}