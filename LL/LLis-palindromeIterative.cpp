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
int count(Node *head){ if(!head) return 0; return 1+count(head->next); }
Node *reverse(Node *head){
	Node *a=NULL; Node *b=head; Node *c=NULL;
	while(b){ c=b->next; b->next=a; a=b; b=c; }
	return a;
}
bool isPalindrome(Node *head){
	if(!head || !head->next)    return true;
	int n=count(head);	int t=n/2;	Node *temp=head;
	while(--t) temp=temp->next;
	temp=reverse(temp->next); //traverse(temp);	cout<<endl;
	t=n/2;//cout<<t<<endl;
	do{ if(head->data!=temp->data) return false; head=head->next; temp=temp->next; }while(--t);
	return true;
}
int main(){
	//freopen("input.txt","r",stdin);
	Node *head = NULL; head=newNode(1); head->next=newNode(2);	head->next->next=newNode(3); head->next->next->next=newNode(3);
		head->next->next->next->next=newNode(2); head->next->next->next->next->next=newNode(1); //head->next->next->next->next->next->next=newNode(1);
//		head->next->next->next->next->next->next->next=newNode(8);
    traverse(head);	cout<<endl;
    cout<<isPalindrome(head);
	cout<<endl;
	return 0;
}
