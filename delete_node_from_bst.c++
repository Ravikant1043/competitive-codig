
//  this function is for getting the address of the node to be deleted
void help(Node *root,int &x,Node* &t,Node* &p){
    if(!root)return;
    if(root->data==x)p=root;
    if(root->left && root->left->data==x)t=root;
    if(root->right && root->right->data==x)t=root;
    
    help(root->left,x,t,p);
    help(root->right,x,t,p);
}
Node *deleteNode(Node *root, int x) {
    if(!root)return root;
    if(root->data==x){
        if(root->left==NULL && root->right==NULL)return NULL;
        Node *p=root->left;
        Node* s=root->right;
        Node *tp=s;
        while(tp->left)tp=tp->left;
        root=root->right;
        tp->left=p;
        return root;
    }
    Node *t=NULL,*p=NULL;
    help(root,x,t,p);
    if(t==NULL)return root;
    bool tp=false;
    if(t->left && t->left->data==x){p=t->left;tp=true;}
    else p=t->right;
    
    if(p->left==NULL && p->right==NULL){
        if(tp)t->left=NULL;
        else t->right=NULL;
    }
    else if(p->left==NULL){
        if(tp)
        t->left=p->right;
        else
        t->right=p->right;
    }
    else if(p->right==NULL){
        if(tp)
        t->left=p->left;
        else
        t->right=p->left;
    }
    else{
        Node* f=p->left;
        Node* s=p->right;
        Node * pp=s;
        while(pp->left){
            pp=pp->left;
        }
        pp->left=f;
        if(tp){
            t->left=f;
        }
        else t->right=f;
    }
    return root;
}
