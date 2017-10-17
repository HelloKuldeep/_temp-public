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
int util(node *root,int sum,int h){
	if(!root) return INT_MAX;
	if(sum==root->data) return h;
	return min( util(root->left,sum-root->data,h+1) , util(root->right,sum-root->data,h+1) );
	
}
int dis(node *root,int sum){
	if(!root) return 0;
	return util(root,sum,0);
}
int main(){
	//freopen("input.txt","r",stdin);
	node *root=newNode(5);
	root->left=newNode(3);	root->right=newNode(6);
	root->left->left=newNode(2);	root->left->right=newNode(4);	root->right->left=newNode(8);	root->right->right=newNode(2);
	cout<<dis(root,12);	cout<<endl;
	return 0;
}
