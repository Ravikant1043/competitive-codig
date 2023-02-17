class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    
    int mod=1e9+7;
  
//   ///////////////////////////////////////////////////// here is the recursive one
    int count(int n,vector<int>&dp){
    //     if(i==n)return 1;
    //     if(i+1<=n)return count(n,i+1)+1;
    //     if(i+2<=n)return count(n,i+2)+1;
    if(dp[n]!=-1)return dp[n];
        if(n==1)return 1;
        if(n==2)return 2;
        int c=0;
        if(n-1>0)c+=(count(n-1,dp)%mod);
        c%=mod;
        if(n-2>0)c+=(count(n-2,dp)%mod);
        c%=mod;
        return dp[n]=c;
    }
    
    // vector<int>dp()
    int countWays(int n)
    {
        // your code here
        // if(n==1)return 1;
        // if(n==2)return 2;
        // int c=0;
        // if(n-1>0)c+=countWays(n-1);
        // if(n-2>0)c+=countWays(n-2);
        // return c;
        // // return count(n,0);
        // vector<int>dp(n+1,-1);
        // dp[1]=1;
        // dp[2]=2;
        // count(n,dp);
        // return dp[n];
        
        //////////////////////////////////////////// here is the tabulation form of this 
        vector<int>dp(n+1,-1);
        dp[1]=1;
        dp[2]=2;
        
        for(int i=3;i<=n;i++){
            dp[i]=(dp[i-1]+dp[i-2])%mod;
        }
        return dp[n];
    }
};




// ///////////////////
//   more optimised one
int a=1,b=2,c;
        if(n<=2)return n;
        // dp[1]=1;
        // dp[2]=2;
        
        for(int i=3;i<=n;i++){
             c=(a+b)%mod;
            a=b;
            b=c;
        }
        return c;
