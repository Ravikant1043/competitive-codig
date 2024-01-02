typedef long long int ll;
class Solution{
    public:    
    long long int maxSumWithK(long long int a[], long long int N, long long int K) 
    {
        // ll pr[n]
        int n=(int)N;
        int k=(int)K;
        // ll m=0;
        // ll pr[n];
        // pr[0]=a[0];
        // m=a[0];
        // for(int i=1;i<n;i++)
        // {
        //     m+=a[i];
        //     pr[i]=m;
        //     if(m<0)m=a[i];
        //     cout<<pr[i]<<" ";
        // }
        // ll t=0;
        // cout<<"\n";
        // for(int i=0;i<k;i++)t+=a[i];
        // ll ans=t;
        // int j=k,i=0;
        // while(j<n){
        //     t+=a[j];
        //     t-=a[i];
            
        //     ans=max(ans,t+pr[i]);
        //     j++;
        //     i++;
        // }
        // return ans;
        
        ll s=0;
        for(int i=0;i<k;i++)s+=a[i];
        ll ans=s;
        ll st=s;
        for(int i=k;i<n;i++){
            s=s+a[i]-a[i-k];
            st=max(st+a[i],s);
            ans=max(ans,st);
        }
        return ans;
    }
};
