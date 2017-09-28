#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left, *right;
};
node *newNode(int key){
	node *temp=new node;
	temp->data=key;	temp->left=NULL; temp->right=NULL;
	return temp;
}
node *insert(node *root,int key){
	if(root==NULL)	return newNode(key);
	if(key<root->data)	root->left=insert(root->left,key);
	else if(key>root->data)	root->right=insert(root->right,key);
	return root;
}
void inorder(node *root){
	if(!root)	return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
int main(){
	//freopen("input.txt","r",stdin);
	node *root = NULL;
    root = insert(root, 50);
    insert(root, 30); insert(root, 20); insert(root, 40); insert(root, 70); insert(root, 60); insert(root, 80);
    inorder(root);
	cout<<endl;
	return 0;
}
