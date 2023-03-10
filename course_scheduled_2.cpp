class Solution {
private:
  
//   ////////////////// this is the topological sorting algo
  
  
  
void totp(vector<int>adj[],int start,vector<int>&vis,vector<int>&ans){
        vis[start]=1;
        for(auto &i:adj[start]){
            if(vis[i]==0)totp(adj,i,vis,ans);
        }
        ans.push_back(start);
    }
  
  /////   here is the cycle detrction technique in the directed graph
  
    bool dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&pathVis){
        vis[node]=1;
        pathVis[node]=1;
        for(auto &it:adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,pathVis)) return true;
            }
            else{
                if(pathVis[it]==1) return true;
            }
        }
        pathVis[node]=0;
        return false;
    }
public:
    vector<int> findOrder(int nc, vector<vector<int>>& prerequisites) {
        
        vector<int>abc[nc];
        for(auto &it:prerequisites){
            int a=it[0];
            int b=it[1];
            abc[b].push_back(a);
        }
        vector<int>vis(nc,0),path(nc,0),ans;
        for(int i=0;i<nc;i++){
            if(vis[i]==0){
              ////////////  if cycle found return empty  vector
                if(dfs(i,abc,vis,path))return {};
            }
        }
        for(int i=0;i<nc;i++)vis[i]=0;
        for(int i=0;i<nc;i++){
            if(vis[i]==0){
                totp(abc,i,vis,ans);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
