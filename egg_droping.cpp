class Solution
{
    public:
    int eggDrop(int k, int n) 
    {
        vector<vector<int>>dp(k+1,vector<int>(n+1,0));
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++){
                if(i==1){
                    dp[i][j]=j;
                }
                else if(j==1)dp[i][j]=1;
                else{
                    int m=INT_MAX;
                    for(int mj=j-1,pj=0;mj>=0;mj--,pj++){
                        m=min(max(dp[i][mj],dp[i-1][pj]),m);
                    }
                    dp[i][j]=m+1;
                }
            }
        }
        return dp[k][n];
    }
};
