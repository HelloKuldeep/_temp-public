#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *next;
};
Node *newNode(int key,Node *head){
	Node *temp=new Node;
	temp->data=key;	temp->next=head;
	return temp;
}
void traverse(Node *head){
	Node *temp=head;
	if(head)do{ cout<<temp->data<<" ";	temp=temp->next; }while(head!=temp);
}
void splitList(Node *head, Node **head1, Node **head2){
	Node *one=head;	Node *two=head;
	if(!head)	return;
	while(two->next!=head && two->next->next!=head){ one=one->next; two=two->next->next; }
	if(two->next->next==head) two=two->next;
	*head1=head;
	if(head->next!=head) *head2=one->next;
	two->next=one->next;
	one->next=head;
}
int main(){
	//freopen("input.txt","r",stdin);
	Node *head = NULL;
    head=newNode(50,NULL);
    head->next=newNode(4,head);	head->next->next=newNode(22,head); head->next->next->next=newNode(113,head); head->next->next->next->next=newNode(1,head); 
    traverse(head);	cout<<endl;
    Node *x,*y;
    splitList(head,&x,&y);
    traverse(x);	cout<<endl;
    traverse(y);	cout<<endl;
	cout<<endl;
	return 0;
}
