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

Node *insert(Node *head,int d){
	Node *temp=NULL;
	if(!head){ temp=newNode(d,NULL); temp->next=temp; }
	return temp;
}
int main(){
	//freopen("input.txt","r",stdin);
	Node *head = NULL;
    head=newNode(50,NULL);
    head->next=newNode(4,head);	head->next->next=newNode(22,head); head->next->next->next=newNode(113,head); head->next->next->next->next=newNode(1,head); 
    traverse(head);	cout<<endl;
    head=insert(head,7);
    traverse(head);	cout<<endl;
	cout<<endl;
	return 0;
}
