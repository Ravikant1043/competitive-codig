long long subarraySum(long long a[], long long n)
    {
        // Your code goes here
        long long ans=0;
        long long i=0,c=1,k=0;
        int mod=1e9+7;
//   here i got the pattern which i have implemented
//   as  n*(i) in a for loop
        while(k<n){
            ans+=(((c%mod)*((n-i)%mod))%mod * a[i])%mod;
            ans%=mod;
            i++;
            c++;
            k++;
        }
        return ans;
    }
