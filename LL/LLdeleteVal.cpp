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
void deleteNode(Node **head,int d){
	Node *temp=*head;
	if(!temp)	return;
	if(temp->data==d){	*head=temp->next;	free(temp);	return;}
	while(temp->next!=NULL && temp->next->data!=d)	temp=temp->next;
	if(!temp->next)	return;
	Node *x=temp->next;	free(x);
	temp->next=temp->next->next;	
}
int main(){
	//freopen("input.txt","r",stdin);
	Node *head = NULL;
    head=newNode(50);
    head->next=newNode(4);	head->next->next=newNode(22); head->next->next->next=newNode(113); head->next->next->next->next=newNode(1);
    traverse(head);	cout<<endl;
    deleteNode(&head,1);
    traverse(head);	cout<<endl;
	cout<<endl;
	return 0;
}
