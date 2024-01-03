class Solution
{
    public:
    //Function to find total number of unique paths.
    int help(int a,int b,int i,int j,vector<vector<int>>&dp){
        if(i==a-1 && j==b-1)return 1;
        if(i>=a||j>=b)return 0;
        int ans=0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(i+1<a){
            ans+=help(a,b,i+1,j,dp);
        }
        if(j+1<b)ans+=help(a,b,i,j+1,dp);
        return dp[i][j]=ans;
    }
    int NumberOfPath(int a, int b)
    {
        vector<vector<int>>dp(a+1,vector<int>(b+1,-1));
        // int ans=0;
        // for(int i=0;i<a;i++){
        //     for(int j=0;j<b;j++){
                
        //     }
        // }
        return help(a,b,0,0,dp);
    }
};
