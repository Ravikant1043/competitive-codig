class Solution {
private:
    void dfs(int i,int j,vector<vector<char>>&mat,vector<vector<int>>&vis,int n,int m){
        vis[i][j]=1;
        // cout<<i<<" "<<j<<endl;
        int di[]={-1,0,1,0};
        int dj[]={0,-1,0,1};
        for(int k=0;k<4;k++){
            int ni=i+di[k];
            int nj=j+dj[k];
            
            if(ni>=0 && ni<n && nj>=0 && nj<m && mat[ni][nj]=='O' && vis[ni][nj]==0){
                dfs(ni,nj,mat,vis,n,m);
            }
        }
    }
public:
    void solve(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(mat[0][i]=='O' && !vis[0][i]){
                dfs(0,i,mat,vis,n,m);
            }
            if(mat[n-1][i]=='O' && !vis[n-1][i]){
                dfs(n-1,i,mat,vis,n,m);
            }
        }
        for(int i=0;i<n;i++){
            if(mat[i][0]=='O' && !vis[i][0])dfs(i,0,mat,vis,n,m);
            if(mat[i][m-1]=='O' && !vis[i][m-1])dfs(i,m-1,mat,vis,n,m);
        }
        // cout<<"\n"<<vis[3][1]<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='O' && vis[i][j]==0)mat[i][j]='X';
            }
        }
    }
};
