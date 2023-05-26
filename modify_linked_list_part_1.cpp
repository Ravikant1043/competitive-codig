class Solution{
    public:
    bool k=true;
  
//     i am uisng a two pointer here to get the last and the first 
    void help(Node *t,Node *&p){
        if(t==NULL){
            return ;
        }
        help(t->next,p);
        if(p==t || t->next==p)k=false;
        if(k){
            int tp=p->data;
            p->data=t->data-tp;
            t->data=tp;
            p=p->next;
        }
    }
    struct Node* modifyTheList(struct Node *head)
    {
        //add code here.
        Node *t=head,*p=head;
        help(t,p);
        return head;
    }
};
