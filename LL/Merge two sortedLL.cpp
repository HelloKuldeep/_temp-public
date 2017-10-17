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
Node* SortedMerge(Node* head1,Node* head2){
	Node *lst=newNode(-99);	Node *temp=lst;
	while(1){
		if(!head1){ lst->next=head2; break; }
		else if(!head2){ lst->next=head1; break; }
		if(head1->data<=head2->data){ lst->next=newNode(head1->data); head1=head1->next; }
		else{ lst->next=newNode(head2->data); head2=head2->next; }
		lst=lst->next;
	}
	return temp->next;
}
int main(){
	//freopen("input.txt","r",stdin);
	Node *head = NULL; head=newNode(2); head->next=newNode(4);	head->next->next=newNode(5); head->next->next->next=newNode(6);
		head->next->next->next->next=newNode(10); head->next->next->next->next->next=newNode(11); head->next->next->next->next->next->next=newNode(12);
		head->next->next->next->next->next->next->next=newNode(20);
	Node *head1 = NULL; head1=newNode(3); head1->next=newNode(7);	head1->next->next=newNode(19);
    traverse(head);	cout<<endl;	traverse(head1);	cout<<endl;
    head=SortedMerge(head,head1);
    traverse(head);	cout<<endl;
	cout<<endl;
	return 0;
}
