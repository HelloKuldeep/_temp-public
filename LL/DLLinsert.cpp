#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *next,*prev;
};
Node *newNode(Node *head,int key){
	Node *temp=new Node;
	temp->data=key;	temp->next=NULL; temp->prev=head;
	return temp;
}
void traverse(Node *head){
	while(head){ cout<<head->data<<" ";	head=head->next; }
}
Node *insertAtHead(Node *head,int d){
	Node *temp=newNode(NULL,d);
	temp->next=head;
	head->prev=temp;
	return temp;
}
void insert(Node *head,int d,int k){
	while(k--)	head=head->next;
	Node *temp=newNode(head,d);
	head->next->prev=temp;
	temp->next=head->next;
	head->next=temp;	
}
int main(){
	//freopen("input.txt","r",stdin);
	Node *head = NULL;
    head=newNode(NULL,50);
    head->next=newNode(head,4);	head->next->next=newNode(head->next,22); head->next->next->next=newNode(head->next->next,113);
    				head->next->next->next->next=newNode(head->next->next->next,1);
    traverse(head);	cout<<endl;
    head=insertAtHead(head,101);
    traverse(head);	cout<<endl;
    insert(head,771,0);
    traverse(head);	cout<<endl;
	cout<<endl;
	return 0;
}
