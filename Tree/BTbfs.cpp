#include<bits/stdc++.h> //O(m+n) or O(n)
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
int height(node *root){
	if(root==NULL) return 0;
	else{
		int l=height(root->left);
		int r=height(root->right);
		if(l>r)	return l+1;
		else return r+1;
	}
}
void print(node *root,int l){
	if(root==NULL)	return;
	if(l==1)	cout<<root->data<<" ";
	else if(l>1){
		print(root->left,l-1);
		print(root->right,l-1);
	}
}
void levelOrder(node *root){
	int n=height(root);
	for(int i=1;i<=n;i++)	print(root,i);
}
int main(){
	//freopen("input.txt","r",stdin);
	node *root=newNode(1);
	root->left=newNode(2);	root->right=newNode(3);
	root->left->left=newNode(4);	root->left->right=newNode(5);	root->right->left=newNode(6);	root->right->right=newNode(7);
	levelOrder(root);	cout<<endl;
	return 0;
}
