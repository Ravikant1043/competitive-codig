/* BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
*/
#include<bits/stdc++.h>

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
// void inor(Node*root,vector<Node*>&ans){
//     if(!root)return ;
//     inor(root->left,ans);
//     ans.push_back(root);
//     inor(root->right,ans);
// }

// ///////////////////////////          actually this is the code for successor of any given key value
void prede(Node *root,Node *&pre,int key){
    if(!root)return;
    if(root->key>key){
//       /////////////////////            here i am comapring the key value with the root->key if greater the calling the left 
        pre=root;
        prede(root->left,pre,key);
    }
    else if(root->key<=key){
//       //////////////////            calling the right tree
        prede(root->right,pre,key);
    }
    // else return;
}


/////////////////////////////////                     this is the code for predecessor of a given bst 
void succe(Node *root,Node *&succ,int key){
    if(!root)return;
    if(root->key>=key){
        // pre=root;
        succe(root->left,succ,key);
    }
    else if(root->key<key){
        succ=root;
        succe(root->right,succ,key);
    }
    // else return;
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    prede(root,suc,key);
    succe(root,pre,key);
