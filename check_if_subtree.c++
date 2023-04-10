/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution
{
  public:
    //Function to check if S is a subtree of tree T.
    bool isIdentical(Node *r1, Node *r2)
    {
//     this is the function for checking the tree is identical or not
        if(r1==NULL || r2==NULL)return r1==r2;
        return (r1->data==r2->data && isIdentical(r1->left,r2->left)
                    && isIdentical(r1->right,r2->right));
        
    }
    bool tatti(Node* t,Node * c){
        if(t==NULL)return false;
        if(t->data==c->data && isIdentical(t,c)){
            return true;
        }
        bool k=false;
        bool p=false;
        k=tatti(t->left,c);
        p=tatti(t->right,c);
        return k||p;
    }
    
    bool isSubTree(Node* T, Node* S) 
    {
        return tatti(T,S);
        // if(tt==NULL)return false;
        // return true;
        // if(tatti())
    }
};
