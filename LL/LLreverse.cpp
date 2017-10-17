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
Node *reverse(Node *head){
	Node *a=NULL; Node *b=head;	Node *c;
	while(b){ c=b->next; b->next=a; a=b; b=c; }
	return a;
}
int main(){
	//freopen("input.txt","r",stdin);
	Node *head = NULL;
    head=newNode(50);
    head->next=newNode(4);	head->next->next=newNode(22); head->next->next->next=newNode(113); head->next->next->next->next=newNode(1);
    traverse(head);	cout<<endl;
    head=reverse(head);
    traverse(head);	cout<<endl;
	cout<<endl;
	return 0;
}
