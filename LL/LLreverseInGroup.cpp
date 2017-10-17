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
Node *reverse(Node *head, int k){
	Node *a=NULL; Node *b=head; Node *c=NULL;
	int ct=0;
	while(b && ct<k){ c=b->next; b->next=a; a=b; b=c; ct++; }
	if(c)	head->next=reverse(c,k);
	return a;
}
int main(){
	//freopen("input.txt","r",stdin);
	Node *head = NULL; head=newNode(1); head->next=newNode(2);	head->next->next=newNode(3); head->next->next->next=newNode(4);
		head->next->next->next->next=newNode(5); head->next->next->next->next->next=newNode(6); head->next->next->next->next->next->next=newNode(7);
		head->next->next->next->next->next->next->next=newNode(8);
    traverse(head);	cout<<endl;
    head=reverse(head,3);
    traverse(head);	cout<<endl;
	cout<<endl;
	return 0;
}
