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
int sea(int in[],int r,int n){
	for(int i=0;i<n;i++)	if(in[i]==r)	return i;
	else return -1;
}
void mpcal(node *root,int d,map<int,vector<int> > &mp){
	if(!root)	return;
	mp[d].push_back(root->data);
	mpcal(root->left,d+1,mp);
	mpcal(root->right,d,mp);
}
void levelOrder(node *root){
	map<int,vector<int> > mp;
	mpcal(root,0,mp);
	map<int,vector<int> >::iterator it;
	vector<int>::iterator it2;
	for(it=mp.begin();it!=mp.end();it++){
		for(it2=it->second.begin();it2!=it->second.end();it2++)
			cout<<*it2<<" ";
		cout<<endl;
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
