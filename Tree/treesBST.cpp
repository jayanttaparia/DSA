#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;
}*root;

Node *GetNewNode(int  data){
	Node *ptr = new Node();
	ptr->data = data;
	ptr->left = ptr->right = NULL;
	return ptr;
}


Node *Insert(Node *root, int data){
	if(root == NULL){
		root = GetNewNode(data);
	}else if(data <= root->data){
		root->left = Insert(root->left, data);
	}else{
		root->right = Insert(root->right,data);
	}
	return root;
}

Node *FindMax(Node *root){
	Node *temp = root;
	while(temp ->right != NULL){
		temp=temp->right;
	}
	return temp;
}

Node *Delete(Node *root, int data){
	if (root == NULL)
	{
		return root;
	}
	else if(data < root->data){
		root->left = Delete(root->left, data);
	}
	else if (data > root->data){
		root->right = Delete(root->right, data);
	}
	else{
		if (root->right == NULL && root->left == NULL){
			free(root);
			root = NULL;
		}
		else if (root->right == NULL)
		{
			Node *temp = new Node();
			temp = root;
			root = root->left;
			delete(temp);
		}
		else if (root->left == NULL)
		{
			Node *temp = new Node();
			temp = root;
			root = root->right;
			delete(temp);
		}else{
			Node *temp = FindMax(root->left);
			root->data = temp->data;
			root->left = Delete(root->left, temp->data);
		}
	}
	return root;
}

void Inorder(Node *root){
	if(root == NULL){
		return;
	}else{

		Inorder(root->left);
		cout<<root->data<<" ";
		Inorder(root->right);
	}
}

int main(){

	root = NULL;
	root = Insert(root, 3);
	root = Insert(root, 5);
	root = Insert(root, 1);
	root = Insert(root, 32);
	root = Insert(root, 33);
	root = Insert(root, 52);
	root = Insert(root, 12);
	root = Delete(root, 33);

	Inorder(root);
	return 0;
}