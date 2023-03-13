also known as the khans algorithm


vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    int ind[V]={0};
	    queue<int>q;
	    for(int i=0;i<V;i++){
	        for(auto &j:adj[i])ind[j]++;
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
	            ind[j]--;
	            if(ind[j]==0)q.push(j);
	        }
	    }
	    return ans;
	    
	}
