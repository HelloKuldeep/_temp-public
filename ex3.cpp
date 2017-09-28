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
void removeLoop(Node *loop,Node *head){
	while(loop->next!=head->next){ loop=loop->next; head=head->next; }	//imp to write loop->next and head->next in while
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
    head=newNode(50);
    head->next=newNode(4);	head->next->next=newNode(22); head->next->next->next=newNode(113); head->next->next->next->next=newNode(1);
	    head->next->next->next->next->next=head->next;
    //traverse(head);	cout<<endl;
    removeTheLoop(head);
    traverse(head);	cout<<endl;
	cout<<endl;
	return 0;
}
