
class Solution{   

// here we are given two arrays from which we need to find the pairs of no one from each so that x^y is always greater than y^x
public:
    long long countPairs(int x[], int y[], int m, int n) {
        // code here
        sort(x,x+m);
        sort(y,y+n);
        long long ans=0;
        
        int one=0,two=0,three=0,four=0;
        for(int i=0;i<n;i++){
            if(y[i]==1)one++;
            if(y[i]==2)two++;
            if(y[i]==3)three++;
            if(y[i]==4)four++;
        }
        int t=0;
        for(int i=0;i<m;i++){
            if(x[i]==1)continue;
            if(x[i]==2){
                t=n-(upper_bound(y,y+n,x[i])-y);
                // cout<<t<<" ";
                // t++;
                // ans+=t;
                ans-=four;
                ans-=three;
                ans+=one;
            }
            else if(x[i]==3){
                t=n-(upper_bound(y,y+n,x[i])-y);
                ans+=one;
                ans+=two;
            }
            else{
                t=n-(upper_bound(y,y+n,x[i])-y);
                ans+=one;
            }
            ans+=t;
            // cout<<ans<<" ";
            t=0;
            
        }
        // cout<<t<<" ";
        return ans;
    }
};
