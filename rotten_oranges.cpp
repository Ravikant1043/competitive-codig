 public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
      
      
//       using  the bfs traversal for counting the time
//       doing the level order traversal of the graph
      
      
        queue<pair<pair<int,int>,int>>qu;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)
                {
                    vis[i][j]=2;
                    qu.push({{i,j},0});
                }
                else vis[i][j]=0;
                if(grid[i][j]==1)fresh++;
            }
        }
        // cout<<fresh<<endl;
        int drow[]={-1,1,0,0};
        int dcol[]={0,0,-1,1};
        int tt=0;
        while(!qu.empty()){
            int nn=qu.size();
            for(int i=0;i<nn;i++){
                int row=qu.front().first.first;
                int col=qu.front().first.second;
                int t=qu.front().second;
                qu.pop();
                tt=max(tt,t);
                for(int k=0;k<4;k++){
                  
//                   calculation of the new row and new col in all the directions for getting the all possiblity
                    int nrow=row+drow[k];
                    int ncol=col+dcol[k];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
                     && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1){
                        vis[nrow][ncol]=2;
                        qu.push({{nrow,ncol},t+1});
                        fresh--;
                    }
                }
            }
//           fresh variable is usied to count the number of the fresh oranges availiable
        }
        if(fresh)return -1;
        return tt;
        
    }
