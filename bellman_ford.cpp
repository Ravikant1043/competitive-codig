/*
  this algorithm is used to detect the negative weight graph or the graph which contains the negative cycle
  -------> this is only aplicable on the directed graph 
*/

vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int>ans(V,1e8);
        ans[S]=0;
        for(int i=0;i<V-1;i++){
            for(auto &it:edges){
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                if(ans[u]!=1e8 && ans[u]+wt<ans[v]){
                    ans[v]=ans[u]+wt;
                }
            }
        }
  // here it checks that the given graph is negative weighted or not
  
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            if(ans[u]!=1e8 && ans[u]+wt<ans[v]){
                return {-1};
            }
        }
        return ans;
    }
