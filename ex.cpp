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
int height(node *root){
    if(!root)   return 0;
    else{
        int l=height(root->left);
        int r=height(root->right);
        if(l>r) return l+1;
        else return r+1;
    }
}
int print(node *root,int n){
    if(!root)   return 0;
    if(n==1)    return 1;
    else if(n>1)	return (print(root->left,n-1) + print(root->right,n-1));
}
int getMaxWidth(node* root){
    int n=height(root),ans=0,d;
    for(int i=1;i<=n;i++){
        d=print(root,i);
        ans=max(ans,d);
    }
    return ans;
}
int main(){
	//freopen("input.txt","r",stdin);
	node *root=newNode(1);
	root->left=newNode(2);	root->right=newNode(3);
	root->left->left=newNode(4);	root->left->right=newNode(5);	root->right->left=newNode(6);	root->right->right=newNode(7);
	cout<<getMaxWidth(root);
	cout<<endl;
	return 0;
}
