class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(vector<int> &vis, vector<int> &pathvis, vector<int> adj[],int node){
        vis[node]=1;
        pathvis[node]=1;
//        maintaining the path visited array tocheck for a particular path
        for(auto &it:adj[node]){
            if(vis[it]==0 && dfs(vis,pathvis,adj,it)==true)return true;
            else if(pathvis[it])return true;
        }
        pathvis[node]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>vis(V,0),pathvis(V,0);
        for(int i=0;i<V;i++){
            if(vis[i]==0  && dfs(vis,pathvis,adj,i)==true){
                return true;
            }
        }
        return false;
    }
};
