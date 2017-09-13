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
void reverselevelOrder(node *root){
	if(!root)	return;
	stack<node*> st;	queue<node*> qu;
	qu.push(root);
	while(!qu.empty()){
		node *temp=qu.front();	qu.pop();
		st.push(temp);
		if(temp->right)	qu.push(temp->right);
		if(temp->left)	qu.push(temp->left);
	}
	while(!st.empty()){
		node *temp=st.top();	st.pop();
		cout<<temp->data<<" ";
	}
}
int main(){
	//freopen("input.txt","r",stdin);
	node *root=newNode(1);
	root->left=newNode(2);	root->right=newNode(3);
	root->left->left=newNode(4);	root->left->right=newNode(5);	root->right->left=newNode(6);	root->right->right=newNode(7);
	reverselevelOrder(root);	cout<<endl;
	return 0;
}
