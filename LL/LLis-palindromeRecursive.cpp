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
bool util(Node **left,Node *right){
	if(!right) return true;
	bool x=util(left,right->next);
	if(!x)	return x;
	bool y=((*left)->data==right->data);
	*left=(*left)->next;
	return y;
}
bool isPalindrome(Node *head){
	return util(&head,head);
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
