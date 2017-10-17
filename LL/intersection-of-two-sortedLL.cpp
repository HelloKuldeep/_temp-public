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
Node *XYZ(Node *a,Node *b){
	if(!a || !b) return NULL;
    if (a->data < b->data)
        return XYZ(a->next, b);
    if (a->data > b->data)
        return XYZ(a, b->next);
    Node *c = new Node;
    c->data = a->data;
    c->next = XYZ(a->next, b->next);
    return c;
}
void intersection(Node **head_1,Node **head_2,Node **head_3){
	*head_3=XYZ(*head_1,*head_2);
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
