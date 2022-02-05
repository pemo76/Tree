#include <bits/stdc++.h>
using namespace std;

class Node
{
	public:
	int data;
	Node* left;
	Node* right;   
};


void  Preorder(Node* root,vector<int>&ans)
{
	if(root==NULL)
       return;
    ans.push_back(root->data);
    Preorder(root->left,ans);
    Preorder(root->right,ans);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}


Node* newNode(int data)
{
	Node* node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}
	

int main()
{
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

    vector<int>ans;
    Preorder(root,ans);
     
}
