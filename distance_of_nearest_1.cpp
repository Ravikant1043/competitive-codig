class Solution 
{
    public:
    typedef pair<int,pair<int,int>> pp;
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n=grid.size();
	    int m=grid[0].size();
	    vector<vector<int>>vis(n,vector<int>(m,0));
	    
	    priority_queue<pp,vector<pp>,greater<pp>>pq;
// 	    here i am using a priority_queue for the better implementation of the algo
//      goin level by level and counting the distance for each ones 
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1){
	                pq.push({0,{i,j}});
	            }
	        }
	    }
//     both the arrays for going in all the four directions
	    int deli[4]={-1,1,0,0};
	    int delj[4]={0,0,-1,1};
	    while(!pq.empty()){
	        int l=pq.top().first;
	        int i=pq.top().second.first;
	        int j=pq.top().second.second;
	        pq.pop();
	        
	        for(int p=0;p<4;p++){
	           // for(int q=0;q<4;q++){
	                int ni=i+deli[p];
	                int nj=j+delj[p];
	                
	                if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]==0 && vis[ni][nj]==0){
	                   // cout<<i<<" "<<j<<"\n";
	                    vis[ni][nj]=l+1;
	                    pq.push({l+1,{ni,nj}});
	                }
	           // }
	        }
	        
	    }
	    
	    return vis;
	}
};
