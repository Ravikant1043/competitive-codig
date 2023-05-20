
class Solution{
    public:
    bool ispowerof5(long long n){
        long long i=1;
        if(n==1)return true;
        while(1){
            if(i*5==n){
                return true;
            }
            if(i*5>n)break;
            i*=5;
        }
        return false;
    }
    
    int binpower(int a,int b){
        if(b==0)return 1;
        if(b==1)return a;
        if(b&1)return a*binpower(a,b-1);
        return binpower(a*a,b/2);
    }
    
    int help(int i,int n,int sum,string s,int po,vector<int>&dp){
        if(i==n && sum==0)return 0;
        if(i==n)return 55;
        if(dp[i]!=-1)return dp[i];
        int a=INT_MAX,b=INT_MAX;
        if(s[i]=='1'){
            sum+=binpower(2,po);
            if(ispowerof5(sum)){
                a=help(i+1,n,0,s,0,dp)+1;
            }
        }
        b=help(i+1,n,sum,s,po+1,dp);
        return dp[i]=min(a,b);
    }
    int cuts(string s){
        int n=s.size();
        vector<int>dp(n+1);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            int j=i-1;
            if(s[j]=='0')dp[i]=-1;
            else{
                dp[i]=-1;
                int c_ans=INT_MAX;
                long long de=0;
                for(int k=0;k<i;k++){
                    if(s[j-k]=='1'){
                        de+=(1LL<<k);
                        if(ispowerof5(de) && dp[j-k]!=-1){
                            c_ans=min(c_ans,dp[j-k]+1);
                        }
                    }
                }
                if(c_ans!=INT_MAX)dp[i]=c_ans;
            }
        }
        return dp[n];
    }
};










// 2nd approach


class Solution{
    public:
    bool ispowerof5(long long n){
        long long i=1;
        if(n==1)return true;
        while(1){
            if(i*5==n){
                return true;
            }
            if(i*5>n)break;
            i*=5;
        }
        return false;
    }
    
    long long binpower(int a,int b){
        if(b==0)return 1;
        if(b==1)return a;
        if(b&1)return a*binpower(a,b-1);
        return binpower(a*a,b/2);
    }
    
    int help(int i,int n,long long sum,string s,int po){
        if(i>=n && sum==0)return 0;
        if(i>=n)return 1000;
        int a=INT_MAX,b=INT_MAX;
        if(s[i]=='1'){
            sum+=(1<<po);
            if(sum==0)return 1000;
            if(ispowerof5(sum)){
                a=help(i+1,n,0,s,0)+1;
            }
        }
        b=help(i+1,n,sum,s,po+1);
        return min(a,b);
    }
    int cuts(string s){
        reverse(s.begin(),s.end());
        while(1){
            if(s.back()=='0')s.pop_back();
            else break;
        }
        // vector<int>dp(55,-1);
        if(s.size()==0)return -1;
        int n=s.size();
        int tt=help(0,n,0,s,0);
        return tt>=1000?-1:tt;
        
    }
};
