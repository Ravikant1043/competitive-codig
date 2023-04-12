class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
        // Code here
        int i=0,j=n/2;
//        here i am sorting the half of the array and using the algo
        sort(arr.begin(),arr.begin()+j);
        sort(arr.begin()+j,arr.end());
        int ans=0;
        while(i<(n/2)){
            int t=j-n/2;
            ans+=(t);
            while(j<n){
                if(arr[i]>=5*arr[j])
                {
                    ans++;
                    j++;
                }
                else break;
            }
            i++;
        }
        return ans;
    }  
    // 2 8 10 1 1 2    0 3
};
