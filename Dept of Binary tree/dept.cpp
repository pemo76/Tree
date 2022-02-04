#include <bits/stdc++.h>
using namespace std;


class Node
{
	public:
	int data;
	Node* left;
	Node* right;
    
};


int maxDepth(Node* node)
{
	if (node == NULL)
		return -1;
	else
	{
	
		int lDepth = maxDepth(node->left);
		int rDepth = maxDepth(node->right);
	
		/* use the larger one */
		if (lDepth > rDepth)
			return(lDepth + 1);
		else return(rDepth + 1);
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
	
	cout << "Height of tree is " << maxDepth(root);
	return 0;
}


