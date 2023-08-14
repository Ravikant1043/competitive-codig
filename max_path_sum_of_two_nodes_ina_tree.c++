int help(Node *root,int &ans){
        if(!root)return 0;
        int a=help(root->left,ans)+root->data;
        int b=help(root->right,ans)+root->data;
        ans=max({a,b,a+b-root->data,root->data,ans});
        return max({a,b,root->data});
    }
    int findMaxSum(Node* root)
    {
        int ans=INT_MIN;
        help(root,ans);
        return ans==INT_MIN?-1:ans;
    }
