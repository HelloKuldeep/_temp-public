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
void postOrder(node *root){
	if(!root)	return;
	stack<node*> st1,st2;
	node *temp;
	st1.push(root);
	while(!st1.empty()){
		temp=st1.top();	st1.pop();
		st2.push(temp);
		if(temp->left)	st1.push(temp->left);
		if(temp->right)	st1.push(temp->right);
	}
	while(!st2.empty()){
		temp=st2.top();	st2.pop();
		cout<<temp->data<<" ";
	}
}
int main(){
	//freopen("input.txt","r",stdin);
	node *root=newNode(1);
	root->left=newNode(2);	root->right=newNode(3);
	root->left->left=newNode(4);	root->left->right=newNode(5);	root->right->left=newNode(6);	root->right->right=newNode(7);
	postOrder(root);	cout<<endl;
	return 0;
}
