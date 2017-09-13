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
void preOrder(node *root){
	if(!root)	return;
	stack<node*> st;
	st.push(root);
	while(!st.empty()){
		node *temp=st.top();	st.pop();
		cout<<temp->data<<" ";
		if(temp->right)	st.push(temp->right);
		if(temp->left)	st.push(temp->left);
	}
}
int main(){
	//freopen("input.txt","r",stdin);
	node *root=newNode(1);
	root->left=newNode(2);	root->right=newNode(3);
	root->left->left=newNode(4);	root->left->right=newNode(5);	root->right->left=newNode(6);	root->right->right=newNode(7);
	preOrder(root);	cout<<endl;
	return 0;
}
