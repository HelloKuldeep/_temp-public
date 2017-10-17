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
bool range(node *root,int l,int h){ return l<=root->data && root->data<=h; }
bool util(node *root,int l,int h,int &c){
	if(!root) return true;
	bool li=(root->left)?util(root->left,l,h,c):true;
	bool r=(root->right)?util(root->right,l,h,c):true;
	if( li && r && range(root,l,h)){ c++; return true; }
	return false;
}
int getCountSubtree(node *root,int l,int h){
	int c=0;
	util(root,l,h,c);
	return c;
}
int main(){
	//freopen("input.txt","r",stdin);
	node *root=newNode(10);
	root->left=newNode(5);	root->right=newNode(50);
	root->left->left=newNode(1);	/*root->left->right=newNode(4);*/	root->right->left=newNode(40);	root->right->right=newNode(100);
	cout<<getCountSubtree(root,5,45);	cout<<endl;
	return 0;
}
