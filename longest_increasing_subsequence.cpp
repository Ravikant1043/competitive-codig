class Solution
{
    public:
    
//   the dp solution 
//    TC ====== >>>>>>>   O(N^2)      space O(N^2)
    int help(int a[],int n,int pre,int i,vector<vector<int>> &dp){
	    if(i>=n)return 0;
	    int take=0;
	    int nottake=0;
	    
	    if(dp[i][pre+1]!=-1)return dp[i][pre+1];
	    
	    if(pre==-1 || a[i]>a[pre])take=help(a,n,i,i+1,dp)+1;
	    nottake=help(a,n,pre,i+1,dp);
	    
	    return dp[i][pre+1]=max(take,nottake);
	}


    int longestSubsequence(int n, int a[])
    {
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // return help(a,n,-1,0,dp);
        
        
        
        
        // binary search approach
      //  tc ===>>>  O(NlogN) space O(N)
        vector<int>t;
        t.push_back(a[0]);
        for(int i=1;i<n;i++){
            if(t.back()<a[i]){
                t.push_back(a[i]);
            }
            else {
                int ind=lower_bound(t.begin(),t.end(),a[i])-t.begin();
                t[ind]=a[i];
            }
        }
        return t.size();
    }
};
