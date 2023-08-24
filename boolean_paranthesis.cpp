
// its a kind of partition dp
class Solution{
public:
    int mod = 1003;
    int help(int i,int j,string &s,bool istrue,vector<vector<vector<int>>>&dp){
        if(i==j){
            if(istrue)return s[i]=='T';
            else return s[i]=='F';
        }
        if(dp[i][j][istrue]!=-1)return dp[i][j][istrue];
        int ans = 0;
        for(int p=i+1;p<j;p+=2){
            int lt=help(i,p-1,s,1,dp);
            int lf=help(i,p-1,s,0,dp);
            int rt=help(p+1,j,s,1,dp);
            int rf=help(p+1,j,s,0,dp);
            int tt=(lt*rt)%mod;
            int tf=(lt*rf)%mod;
            int ff=(rf*lf)%mod;
            int ft=(lf*rt)%mod;
            
            if(s[p]=='&'){
                if(istrue==true)
                    ans=(ans+tt);
                else ans=(ans+tf+ft+ff);
            }
            else if(s[p]=='|'){
                if(istrue==true)
                    {ans=(ans+tt+tf+ft);}
                else
                    ans=(ans+ff);
            }
            else if(s[p]=='^'){
                if(istrue==true)
                    ans=(ans+tf+ft)%mod;
                else ans=(ans+ff+tt)%mod;
            }
            ans%=mod;
        }
        return dp[i][j][istrue]=ans;
    }
    int countWays(int N, string S){
        vector<vector<vector<int>>>dp(vector<vector<vector<int>>>(N,vector<vector<int>>(N,vector<int>(2,-1))));
        return help(0,N-1,S,1,dp);
    }
};
