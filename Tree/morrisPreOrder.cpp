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
void preOrder(node *root){
	node *curr=root;
	while(curr){
		if(!curr->left){
			cout<<curr->data<<" ";
			curr=curr->right;
		}
		else{
			node *pre=curr->left;
			while(pre->right!=curr && pre->right!=NULL)	pre=pre->right;
			if(!pre->right){
				pre->right=curr;
				cout<<curr->data<<" ";
				curr=curr->left;
			}
			else{
				pre->right=NULL;
				curr=curr->right;
			}
		}
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
