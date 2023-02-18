/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false


// //////////////////////  here i am checking the value of left side as left and value of right side as right are equal or not

class Solution
{
    public:
    bool t=true;
    int treesum(Node *root){
        if(!root)return 0;
        if(root->left==NULL && root->right==NULL)return root->data;
        
        
        int left=0,right=0;
        if(root->left)
            left=treesum(root->left);   // sum of left tree
        
        if(root->right)
            right=treesum(root->right);  //  sum of right tree 
        // if(l+r!=2*root->data)
        if(left+right!=root->data)t=false;
        return left+right+root->data;
    }
    
    
    bool isSumTree(Node* root)
    {
         // Your code here
        //  int l=0,r=0;
         treesum(root);
         return t;
    }
