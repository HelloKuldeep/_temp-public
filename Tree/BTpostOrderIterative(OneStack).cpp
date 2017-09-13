#include<bits/stdc++.h>	//Not Working Now
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
	stack<node*> st;
	do{
		while(root){
			if(root->right)	st.push(root->right);
			st.push(root);
			root=root->left;
		}
		node *temp=st.top();	st.pop();
		root=temp;	temp=st.top();	node *temp2=root->right;
		if(root->right && temp==temp2){
			st.pop();
			st.push(root);
			root=root->right;
		}
		else{
			cout<<root->data<<" ";
			root=NULL;
		}
	}while(!st.empty());
}
int main(){
	//freopen("input.txt","r",stdin);
	node *root=newNode(1);
	root->left=newNode(2);	root->right=newNode(3);
	root->left->left=newNode(4);	root->left->right=newNode(5);	root->right->left=newNode(6);	root->right->right=newNode(7);
	postOrder(root);	cout<<endl;
	return 0;
}
