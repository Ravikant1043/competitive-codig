/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/



class Solution{

    public:
    Node* ho;
  
//   firstly created the link map for maping the child node to the parent node which helps in the traversal for the tree
    void link(unordered_map<Node*,Node*> &mp,Node *root,int h){
        if(!root)return ;
        if(root->data==h)ho=root;
        if(root->left){
            mp[root->left]=root;
            link(mp,root->left,h);
        }
        if(root->right){
            mp[root->right]=root;
            link(mp,root->right,h);
        }
    }
    int ladoos(Node* root, int home, int k)
    {
//        this is for linking function call and checking the edge case 
        if(!root)return 0;
        unordered_map<Node*,Node*> mp;
        mp[root]=NULL;
        
        if(root->left){
            mp[root->left]=root;
            link(mp,root->left,home);
        }
        if(root->right){
            mp[root->right]=root;
            link(mp,root->right,home);
        }
        if(home==root->data)
            ho=root;
      
      
//         queue for the bfs traversal
        queue<pair<int,Node*>> q;
      
//       set for ensuring that ve have viseted that node once only
        unordered_set<Node*>st;
        q.push({0,ho});
        int sum=0;
        
        while(!q.empty()){
            int t=q.front().first;
            Node* n=q.front().second;
            q.pop();
            if(n==NULL || st.find(n)!=st.end())continue;
            if(t>k){
                break;
            }
            if(!n)continue;
            sum+=n->data;
            
            if(n->left){
                q.push({t+1,n->left});
            }
            if(n->right){
                q.push({t+1,n->right});
            }
            if(mp.find(n)->second){
                q.push({t+1,mp.find(n)->second});
            }
            st.insert(n);
        }
        return sum;
    }

};
