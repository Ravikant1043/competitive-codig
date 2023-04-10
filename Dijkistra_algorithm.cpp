class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int s)
    {
        // Code here
        // vector<int>dis(n+2,1e8);
        vector<int>dis(n);
        for(int i=0;i<n;i++)dis[i]=1e8;
      
//       using the priority queue as a min heap to get the shortest path for traversal
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        pq.push({0,s});
        dis[s]=0;
        while(!pq.empty()){
            int diss=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto &it:adj[node]){
                int newdis=diss+it[1];
                if(dis[it[0]]>newdis){
                    dis[it[0]]=newdis;
                    pq.push({newdis,it[0]});
                }
                // cout<<it[0]<<" "<<it[1]<<"\n";
            }
        }
        return dis;
        
    }
};
