#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node *left;
        node *right;
};

node *newNode(int data){
   if(data==NULL)
      return;
    node *n =new node();
    n->data=data;
    n->right=NULL;
    n->left=NULL;
    return n;
}

void inorder(node *n){
    inorder(n->left);
    cout<<n->data<<endl;
    inorder(n->right);
}


node *margetree(node *r1,node *r2){
    if(r1==NULL && r2==NULL)
        return NULL;
    if(r1==NULL)
        return r2;
    if(r2==NULL)
        return r1;
    // node *newNode = new node(r1->data+r2->data);
    // newNode->left = margetree(r1->left,r2->left);
    // newNode->right = margetree(r1->right,r2->right);
    // return newNode;

    r1->data+=r2->data;
    r1->left = margetree(r1->left,r2->left);
    r1->right = margetree(r1->right,r2->right);
    return r1;
}

int main(){
    node *root1 = newNode(10);
	root1->left = newNode(20);
	root1->right = newNode(25);
	root1->left->left = newNode(30);
	root1->left->right = newNode(40);
	root1->left->right->left =newNode(42);
	root1->right->left = newNode(35);
	root1->right->right = newNode(33);
	root1->right->right->right = newNode(46);

    node *root2 = newNode(10);
	root2->left = newNode(20);
	root2->right = newNode(25);
	root2->left->left = newNode(30);
	root2->left->right = newNode(40);
	root2->left->right->left =newNode(42);
	root2->right->left = newNode(35);
	root2->right->right = newNode(33);
	root2->right->right->right = newNode(46);
   
    node *root3 = margetree(root1,root2);
    inorder(root3);

}