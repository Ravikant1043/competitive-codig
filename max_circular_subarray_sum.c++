class Solution{
    public:
    int circularSubarraySum(int arr[], int n){
        int s=0;
      // sum of all the elements of the array 
        for(int i=0;i<n;i++)s+=arr[i];
        
        int sum=0,st=0,mini=INT_MAX;
        // minimum sum subarray code
        for(int i=0;i<n;i++){
          sum+=arr[i];
          if(mini>sum)mini=sum;
          if(sum>0)sum=0;
        }
        
        int an=INT_MIN;
        int ts=0;
        bool check=false;
        
        // kadane's algo
        for(int i=0;i<n;i++){
            ts+=arr[i];
            if(arr[i]>0)check=true;
            if(ts>an)an=ts;
            if(ts<0)ts=0;
        }
        
        // base case for all negative elements
        if(!check)return an;
        return max(an,s-mini);
    }
};
