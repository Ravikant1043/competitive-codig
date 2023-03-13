

class Solution
{
    private:
        void dfs(vector<int>adj[],int start,int vis[],vector<int>&ans){
            vis[start]=1;
            for(auto &i:adj[start]){
                if(vis[i]==0)dfs(adj,i,vis,ans);
            }
            ans.push_back(start);
        }
	public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int vis[V+1]={0};
	    vector<int>ans;
	    for(int i=0;i<V;i++){
	        if(vis[i]==0)dfs(adj,i,vis,ans);
	    }
	   reverse(ans.begin(),ans.end());
	    return ans;
	}
};
