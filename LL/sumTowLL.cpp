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
Node* addTwoLists(Node* first, Node* second){
	if(!first && !second) return NULL;	if(!first) return second;	if(!second) return first;
	Node *head=NULL; Node *temp,*UU=NULL;
	int sum=0,c=0;
	while(first || second){
		sum=c+(first?first->data:0)+(second?second->data:0);
		c=(sum>9)?1:0;
		sum%=10;
		temp=newNode(sum);
		if(!head)	head=temp;
		else UU->next=temp;
		UU=temp;
		if(first)	first=first->next;
		if(second)	second=second->next;
	}
	if(c>0) temp->next=newNode(c);
	return head;
}
int main(){
	//freopen("input.txt","r",stdin);
	Node *head = NULL; head=newNode(51); head->next=newNode(4);	
    Node *head2 = NULL; head2=newNode(5); head2->next=newNode(4); head2->next->next=newNode(3);
    traverse(head);	cout<<endl;
    traverse(head2);	cout<<endl;
    Node *temp=addTwoLists(head,head2);
    traverse(temp);	cout<<endl;
	cout<<endl;
	return 0;
}
