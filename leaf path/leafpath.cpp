#include<bits/stdc++.h>
using namespace std;

class node{
    public:
       int data;
       node *left;
       node *right;
};


node *newNode(int data){
    node *Node =new node();
    Node->data =data;
    Node->left =NULL;
    Node->right =NULL;
    return(Node);
}



void pathfind(node *root,vector<string>&res,string curr){
    if(root==NULL)
        return;
    if(root->left==NULL && root->right==NULL){
        curr+=to_string(root->data);
        res.push_back(curr);
        return;
    }
    cout << to_string(root->data)+ "->";
    if(root->left)
        pathfind(root->left,res,curr);
    if(root->right)
        pathfind(root->right,res,curr);
}


vector<string>pathprint(node *root){
    vector<string>res;
    pathfind(root,res,"");
    return res;
}


int main(){
    node *root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(7);
    root->left->left = newNode(5);
    root->left->right = newNode(6);
    root->left->right->left = newNode(3);
    root->right->left = newNode(34);
    root->right->right = newNode(1);

    pathprint(root);
}