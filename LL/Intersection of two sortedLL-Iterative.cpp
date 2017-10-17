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
int sumList(Node *head){
	int a=0,x=1;
	while(head){ a+=head->data*x; x*=10; head=head->next; }
	return a;
}
void intersection(Node **head_1,Node **head_2,Node **head3){
	Node *head1=*head_1;	Node *head2=*head_2;
	*head3=NULL;
	if(!head1 || !head2) return;
	Node *temp,*UU=NULL;
	while(head1 && head2){
		if(head1->data==head2->data){
			temp=newNode(head1->data);
			head1=head1->next; head2=head2->next;
			if(!*head3)	*head3=temp;
			else UU->next=temp;
			UU=temp;
		}
		else if(head1->data<head2->data){ head1=head1->next; }
		else if(head1->data>head2->data){ head2=head2->next; }
	}
}
int main(){
	//freopen("input.txt","r",stdin);
	Node *head = NULL; head=newNode(1); head->next=newNode(2);	head->next->next=newNode(3); head->next->next->next=newNode(4);
		head->next->next->next->next=newNode(6);
	Node *head2 = NULL; head2=newNode(2); head2->next=newNode(4);	head2->next->next=newNode(6); head2->next->next->next=newNode(8);
    traverse(head);	cout<<endl;
    traverse(head2);	cout<<endl;
    Node *head3;
    intersection(&head,&head2,&head3);	cout<<endl;
    traverse(head3);	cout<<endl;
	cout<<endl;
	return 0;
}
