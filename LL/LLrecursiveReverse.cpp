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
void recursiveReverse(Node **head){
	Node* first;Node* rest;
    if (*head == NULL)return;   
    first = *head;  
    rest  = first->next;
    if (rest == NULL)
       return;   
    recursiveReverse(&rest);
    first->next->next  = first;  
    first->next  = NULL;          
    *head = rest;
}
int main(){
	//freopen("input.txt","r",stdin);
	Node *head = NULL;
    head=newNode(50);
    head->next=newNode(4);	head->next->next=newNode(22); head->next->next->next=newNode(113); head->next->next->next->next=newNode(1);
    traverse(head);	cout<<endl;
    recursiveReverse(&head);
    traverse(head);	cout<<endl;
	cout<<endl;
	return 0;
}
