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
int levelk(node *a,node *b){
	if(!a && !b) return 1;
    if(!a || !b) return 0;
    if(a->data != b->data)   return 0;
    return ((a->data == b->data) && areMirror(a->left,b->right) 
            && areMirror(a->right,b->left));
}
int main(){
	//freopen("input.txt","r",stdin);
	node *root=newNode(1);
	root->left=newNode(2);	root->right=newNode(3);
	root->left->left=newNode(4);		root->right->left=newNode(6);	root->right->right=newNode(7);
	node *root2=newNode(1);
	root2->left=newNode(3);	root2->right=newNode(2);
	root2->left->left=newNode(7);	root2->left->right=newNode(6);	root2->right->right=newNode(4);
	cout<<levelk(root,root2);
	//levelOrder(root);	cout<<endl;	levelOrder(root2);
	cout<<endl;
	return 0;
}
