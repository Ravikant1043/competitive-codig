class Solution {
private:
    vector<int> topoSort(int V, vector<pair<int,int>> adj[]) 
	{
	    int ind[V]={0};
	    queue<int>q;
	    for(int i=0;i<V;i++){
	        for(auto &j:adj[i])ind[j.first]++;
	    }
	    
	    for(int i=0;i<V;i++){
	        if(ind[i]==0)q.push(i);
	    }
	    vector<int>ans;
	    while(!q.empty()){
	        int t=q.front();
	        q.pop();
	        ans.push_back(t);
	        for(auto &j:adj[t]){
	            ind[j.first]--;
	            if(ind[j.first]==0)q.push(j.first);
	        }
	    }
	    return ans;
	}
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>>adj[N];
        for(auto &e:edges){
            adj[e[0]].push_back({e[1],e[2]});
        }
        vector<int>top=topoSort(N,adj);
        vector<int>ans(N,INT_MAX);
        ans[0]=0;
        //// i got the topological sort of the given graph and the i have iterated to all the adjacent edges of that particular edges
        for(int i=0;i<top.size();i++){
            int t=top[i];
            if(ans[t]==INT_MAX){ans[t]=100;}
            int s=ans[t];
            if(adj[t].size()==0)break;
            for(auto &it:adj[t]){
                ans[it.first]=min(ans[it.first],s+it.second);
            }
            if(ans[t]==100)ans[t]=-1;
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i]==INT_MAX)ans[i]=-1;
        }
        return ans;
    }
};
