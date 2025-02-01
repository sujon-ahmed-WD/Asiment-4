#include<bits/stdc++.h>
using  namespace std;

class Node{
    public:
    int val;
    Node*left;
    Node*right;
    Node(int val)
    {
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
 
};
Node* input_tree()
{
    int val; cin>>val;
    Node* root;
    if(val==-1)  root=NULL;
    else root =new Node(val);
    queue<Node*>q;
    if(root) q.push(root);
    while(!q.empty())
    {
        Node* prant=q.front();
        q.pop();


        int l,r;cin>>l>>r;
        Node*myright,*myleft;
        if(l==-1)  myleft=NULL;
        else myleft=new Node(l);
        if(r==-1)  myright=NULL;
        else myright= new Node(r);
        prant->left=myleft;
        prant->right=myright;


        if(prant->left)
        q.push(prant->left);
        if(prant->right)
        q.push(prant->right);
    }
    return root;
}

 
vector<int>v;
void leaf_Node(Node* root)
{
    if(root==NULL)
    return ;

    if(root->left==NULL && root->right==NULL)
    {
        v.push_back(root->val);
    }
 
    leaf_Node(root->left);
    leaf_Node(root->right);
    
};
 

int main()
{
    Node* root=input_tree();
    leaf_Node(root);
  sort(v.begin(),v.end(),greater<int>());
  for(int c:v)
  {
    cout<<c<<" ";
  }

  


    return 0;
}