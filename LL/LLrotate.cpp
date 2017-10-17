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
void traverse(Node *head){	while(head){ cout<<head->data<<" ";	head=head->next; } }
void rotate(Node **head, int k){
	Node *temp=*head; int ct=1;
	while(temp && ct<k){ temp=temp->next; ct++; }
	if(!temp)	return;
	Node *n=temp;
	while(temp->next) temp=temp->next;
	temp->next=*head;
	*head=n->next;
	n->next=NULL;
}
int main(){
	//freopen("input.txt","r",stdin);
	Node *head = NULL; head=newNode(1); head->next=newNode(2);	head->next->next=newNode(3); head->next->next->next=newNode(4);
		head->next->next->next->next=newNode(5); head->next->next->next->next->next=newNode(6); //head->next->next->next->next->next->next=newNode(7);
		//head->next->next->next->next->next->next->next=newNode(8);
    traverse(head);	cout<<endl;
    rotate(&head,4);
    traverse(head);	cout<<endl;
	cout<<endl;
	return 0;
}
