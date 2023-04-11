class Solution
{
    public:
    bool dfs(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis,int n,int m,int e,int ee){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j] ==0 || vis[i][j] ==1)return false;
        vis[i][j]=1;
        if(i==e && j==ee)return true;
        int f=false,s=false,ff=false,ss=false;
         // here i am checking all the directions where i can find it
         
         
        f=dfs(i+1,j,grid,vis,n,m,e,ee);
        s=dfs(i,j+1,grid,vis,n,m,e,ee);
        ff=dfs(i-1,j,grid,vis,n,m,e,ee);
        ss=dfs(i,j-1,grid,vis,n,m,e,ee);
        return f||s||ff||ss;
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int si,sj;
        int ei,ej;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    si=i;
                    sj=j;
                }
                if(grid[i][j]==2){
                    ei=i;
                    ej=j;
                }
            }
        }
        vector<vector<int>>vis(n,vector<int>(m,0));
        return dfs(si,sj,grid,vis,n,m,ei,ej);
    }
};
