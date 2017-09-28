#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *next,*prev;
};
Node *newNode(Node *head,int key){
	Node *temp=new Node;
	temp->data=key;	temp->next=NULL; temp->prev=head;	//if(head)head->next=temp;
	return temp;
}
void traverse(Node *head){
	while(head){ cout<<head->data<<" ";	head=head->next; }
}
void reverse(Node **head){
    int l=0;    Node *temp2=*head;
    while(temp2->next){ temp2=temp2->next; l++; }  l++;
    Node *temp=*head;
    l/=2;
    while(l--){ swap(temp->data,temp2->data); temp=temp->next; temp2=temp2->prev; }
}
int main(){
	//freopen("input.txt","r",stdin);
	Node *head = NULL;
    head=newNode(NULL,50);
    head->next=newNode(head,4);	head->next->next=newNode(head->next,22); head->next->next->next=newNode(head->next->next,113);
    				head->next->next->next->next=newNode(head->next->next->next,1);
    traverse(head);	cout<<endl;
    reverse(&head);
    traverse(head);	cout<<endl;
	cout<<endl;
	return 0;
}
