#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *next,*prev;
};
Node *newNode(Node *head,int key){
	Node *temp=new Node;
	temp->data=key;	temp->next=NULL; temp->prev=head;	//if(head)head->next=temp;
	return temp;
}
void traverse(Node *head){
	while(head){ cout<<head->data<<" ";	head=head->next; }
}
void addNode(Node **tempor,int k,int d){
    Node *head=*tempor;
	while(k--)	head=head->next;
	Node *temp=new Node;//(head,d);
	temp->data=d;	temp->next=head->next; temp->prev=head;
	if(head->next) head->next->prev=temp;
	head->next=temp;	
}
int main(){
	//freopen("input.txt","r",stdin);
	Node *head = NULL;
    head=newNode(NULL,50);
    head->next=newNode(head,4);	head->next->next=newNode(head->next,22); head->next->next->next=newNode(head->next->next,113);
    				head->next->next->next->next=newNode(head->next->next->next,1);
    traverse(head);	cout<<endl;
    addNode(&head,4,101);
    traverse(head);	cout<<endl;
	cout<<endl;
	return 0;
}
