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
int findMinSum(node *root){
	if(!root) return 0;
	int s=root->data;
	int l=findMinSum(root->left); int r=findMinSum(root->right);
	s+=(min(l,r)==l)?findMinSum(root->left):findMinSum(root->right);
	return s;
}
int main(){
	//freopen("input.txt","r",stdin);
	node *root=newNode(5);
	root->left=newNode(3);	root->right=newNode(6);
	root->left->left=newNode(2);	root->left->right=newNode(4);	root->right->left=newNode(8);	root->right->right=newNode(7);
	cout<<findMinSum(root);	cout<<endl;
	return 0;
}
