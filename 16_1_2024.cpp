int help(int n,int m,vector<vector<int>>& dp){
        if(n==1)return m;
        if(m<n)return 0;
        if(dp[m][n]!=-1)return dp[m][n];
        return dp[m][n]= help(n-1,m/2,dp) + help(n,m-1,dp);
    }
    int numberSequence(int m, int n){
        if(n>7)return 0;
        vector<vector<int>>dp(101,vector<int>(101,-1));
        return help(n,m,dp);
    }
