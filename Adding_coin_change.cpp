Given three integers n, k, target, and an array of coins of size n. Find if it is possible to make a change of target cents by using an infinite supply of each coin but the total number of coins used must be exactly equal to k.

Example 1:

Input:
n = 5, k = 3, target = 11
coins = {1, 10, 5, 8, 6}

Output: 
1

Explanation: 
2 coins of 5 and 1 coins of 1 can be used 
to make change of 11 i.e. 11 => 5+5+1.
Example 2:

Input:
n = 3, k = 5, target = 25
coins = {7, 2, 4}

Output:
1

Explanation:
3 coins 7, 2 coins of 2 can be used to
make change of 25 i.e. 25 => 7+7+7+2+2.
Your Task:
This is a function problem. You only need to complete the function makeChanges() that 3 integers n, k, target, and an array coins as parameters and return True or False.

Expected Time Complexity: O(n*k*target)
Expected Space Complexity: O(k*target)

Constraints:
1 <= n, k, coins[i] <= 100
1 <= target <= 1000


  
//   //////////////////////// Solution

class Solution {
  public:
    // bool tt=false;
    bool help(vector<int>&coins, int n,int k,int t,vector<vector<int>>&dp){
        if(n==-1){
            if(t==0 && k==0){
                return 1;
            }
            return 0;
        }
        if(t==0 && k==0){
            // tt=true;
            return 1;
        }
        if(dp[k][t]!=-1)return dp[k][t];
        // if(n==0)return ;
        bool tt=0,nt=0;
        nt=help(coins,n-1,k,t,dp);
        if(k && t>=coins[n])
        tt=help(coins,n,k-1,t-coins[n],dp);
        return dp[k][t]=(nt||tt);
    }
    // 1 5 6 8 10
    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        // code here
        sort(coins.begin(),coins.end());
        vector<vector<int>>dp(K+1,vector<int>(target+1,-1));
        help(coins,N-1,K,target,dp);
        // return tt;
        return dp[K][target];
    }
};
