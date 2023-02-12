

// here we are calculating the nCr of any number using dp
// as it follows the pattern of pascals triangle 
// if we check the pattern of pascals triangle
// 1
// 11
// 121
// 1331
// 14641
// the new element in a new row is the sum of the the previous number and the current number of the previous row




class Solution{
public:
    int nCr(int n, int r){
        if(n<r)return 0;
        if((n-r)<r)r=n-r;
        int mod=1e9+7;
        int dp[r+1]={0};
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=min(i,r);j>=1;j--){
                dp[j]=(dp[j]+dp[j-1])%mod;
            }
        }
        return dp[r];
        
    }
};
