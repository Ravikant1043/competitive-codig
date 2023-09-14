/*
    this is a game theory question
    the main trick to get a optimal sol is that to give out the optimized out of the 
        worst cases for all the eggs to be dropped
    here either i can check after droping a egg that that eggs gets broken or it survives
        if it survivrs then one case or if it doesn't then one case => and then taking the
        maximum out of both and after taking the min of all the cases from the first floor 
        the top floor
*/
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
