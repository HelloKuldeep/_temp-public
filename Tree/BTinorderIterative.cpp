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
void InOrder(node *root){
	if(root==NULL)	return;
	stack<node*> st;
	int d=1;
	while(d){
		if(root){
			st.push(root);	root=root->left;
		}
		else{
			if(!st.empty()){
				root=st.top();	st.pop();
				cout<<root->data<<" ";
				root=root->right;
			}
			else d=0;
		}
	}
}
int main(){
	//freopen("input.txt","r",stdin);
	node *root=newNode(1);
	root->left=newNode(2);	root->right=newNode(3);
	root->left->left=newNode(4);		root->right->left=newNode(6);	root->right->right=newNode(7);
	InOrder(root);	cout<<endl;
	return 0;
}
