// using post order traversal to add all the elements
void help(Node *root,int &val){
    if(!root)return;
    help(root->right,val);
    root->data+=val;
    val=root->data;
    help(root->left,val);
}

Node* modify(Node *root)
{
    int t=0;
  // call of the function help to add the elements
    help(root,t);
    return root;
}
