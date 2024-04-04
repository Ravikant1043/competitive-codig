typedef long long ll;
int mod=1e9+7;
class Solution
{
    public:
    int n;
    ll ans=0;
    ll help(int i,string &s,ll &p){
        if(i==n)return 0;
        p=((p%mod * 10%mod)%mod + (s[i]-'0')%mod)%mod;
        ans=(ans+p)%mod;
        return help(i+1,s,p);
    }
    long long sumSubstrings(string s){
        n=s.size();
        // for(int i=0;i<n;i++){
        //     ll p=0;
        //     help(i,s,p);
        // }
        ll a=1;
        for(int i=n-1;i>=0;i--){
            ans=(ans+ (s[i]-'0')*a*(i+1))%mod;
            a=((a*10)%mod +1)%mod;
        }
        return ans;
    }
};
