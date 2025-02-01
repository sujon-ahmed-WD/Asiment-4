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

         prant->left=mylift;
         prant->right=myright;     

        if (prant->left)
            q.push(prant->left);
        if (prant->right)
            q.push(prant->right);
    }
    return root;
}

void print_kth_level(Node *root, int k)
{
    if (root == NULL)
    {

        cout << "Invalid";
        return;
    }

    vector<int> level_node;

    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        Node *node = q.front().first;
        int level = q.front().second;
        q.pop();

        if (level == k)
            level_node.push_back(node->val);

        if(node->left)
            q.push({node->left,level+1});
        if(node->right)
        q.push({node->right,level+1});        

    }
    if(level_node.empty())
    cout<<"Invalid";
    else
    {
        for(int val: level_node)
        {
            cout<<val<<" ";
        }
    }

}

int main()
{
    Node *root = input_tree();
    int k;
    cin >> k;
    print_kth_level(root,k);

    return 0;
}