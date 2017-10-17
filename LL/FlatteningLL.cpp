Node *merge(Node *a,Node *b){
    if(!a) return b;
    if(!b) return a;
    Node *temp;
    if(a->data<b->data){ temp=a; temp->bottom=merge(a->bottom,b); }
    else{ temp=b; temp->bottom=merge(a,b->bottom); }
    return temp;
}
Node *flatten(Node *root){
	if(!root || !root->next)	return root;
	return merge(root,flatten(root->next));
}
