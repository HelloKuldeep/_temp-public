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
void levelOrder(node *root){
	if(root==NULL)	return;
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node *temp=q.front();	q.pop();
		cout<<temp->data<<" ";
		if(temp->left)	q.push(temp->left);
		if(temp->right)	q.push(temp->right);
	}
}
int main(){
	//freopen("input.txt","r",stdin);
	node *root=newNode(1);
	root->left=newNode(2);	root->right=newNode(3);
	root->left->left=newNode(4);	root->left->right=newNode(5);	root->right->left=newNode(6);	root->right->right=newNode(7);
	levelOrder(root);	cout<<endl;
	return 0;
}
