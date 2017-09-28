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
Node *insertAtHead(Node *head,int d){
	Node *temp=newNode(d);
	temp->next=head;
	head=temp;
	return head;
}
void insert(Node *head,int d,int k){
	while(--k)	head=head->next;
	Node *temp=newNode(d);
	temp->next=head->next;
	head->next=temp;
}
void insertAtEnd(Node *head,int d){
	while(head->next)	head=head->next;
	Node *temp=newNode(d);
	head->next=temp;
	temp->next=NULL;
}
int main(){
	//freopen("input.txt","r",stdin);
	Node *head = NULL;
    head=newNode(50);
    head->next=newNode(4);	head->next->next=newNode(22); head->next->next->next=newNode(113); head->next->next->next->next=newNode(1);
    traverse(head);	cout<<endl;
    head=insertAtHead(head,1001);
    traverse(head);	cout<<endl;
    insert(head,7,3);
    traverse(head);	cout<<endl;
    insertAtEnd(head,711);
    traverse(head);	cout<<endl;
	cout<<endl;
	return 0;
}
