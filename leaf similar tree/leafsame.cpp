#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *right;
    node *left;
};

node *newNode(int data){
    node *n = new node();
    n->data=data;
    n->right=NULL;
    n->left=NULL;
}

void inorder(node *n){
    inorder(n->left);
    cout<< n->data <<" ";
    inorder(n->right);
}


void travl(node *root,vector<int>&v){
    if(root==NULL)
          return;
    if(root->left==NULL && root->right==NULL){
        v.push_back(root->data);
    }

    if(root->left!=NULL){
        travl(root->left,v);
    }
    if(root->right!=NULL){
        travl(root->right,v);
    }
}

bool checkleaf(node *r1,node *r2){
    vector<int>a;
    vector<int>b;
    travl(r1,a);
    travl(r2,b);
    return a==b;
}


int main(){
   node *root1 = newNode(3);
	root1->left = newNode(5);
	root1->right = newNode(1);
	root1->left->left = newNode(6);
	root1->left->right = newNode(2);
	root1->left->right->left =newNode(7);
    root1->left->left->right = newNode(4);
	root1->right->left = newNode(9);
	root1->right->right = newNode(8);

    node *root2 = newNode(3);
	root2->left = newNode(5);
	root2->right = newNode(1);
	root2->left->left = newNode(6);
	root2->left->right = newNode(7);
	root2->right->left =newNode(4);
	root2->right->right = newNode(2);
	root2->right->right->left = newNode(9);
	root2->right->right->right = newNode(8);

    cout<<checkleaf(root1,root2);
}