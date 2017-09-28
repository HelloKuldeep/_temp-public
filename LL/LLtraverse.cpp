#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *next;
};
Node *newNode(int key){
	Node *temp=new Node;
	temp->data=key;	temp->next=NULL;
	return temp;
}
void traverse(Node *head){
	while(head){ cout<<head->data<<" ";	head=head->next; }
}
int main(){
	//freopen("input.txt","r",stdin);
	Node *head = NULL;
    head=newNode(50);
    head->next=newNode(4);	head->next->next=newNode(22);
    traverse(head);
	cout<<endl;
	return 0;
}
