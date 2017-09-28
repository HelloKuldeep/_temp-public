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
void removeLoop(Node *loop,Node *head){
	while(loop!=head){ loop=loop->next; head=head->next; }
	loop->next=NULL;
}
void removeTheLoop(Node *head){
    if(!head || !head->next) return;
	Node *one=head;	Node *two=head;
	while(two && two->next){
		one=one->next;
		two=two->next->next;
		if(one==two){ removeLoop(one,head); return;}
	}
	return;
}
int main(){
	//freopen("input.txt","r",stdin);
	Node *head = NULL;
    head=newNode(50,NULL);
    head->next=newNode(4,head);	head->next->next=newNode(22,head); head->next->next->next=newNode(113,head); head->next->next->next->next=newNode(1,head); 
    traverse(head);	cout<<endl;
    removeTheLoop(head);
    traverse(head);	cout<<endl;
	cout<<endl;
	return 0;
}
