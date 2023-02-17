class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to rearrange an array so that arr[i] becomes arr[arr[i]]
    //with O(1) extra space.
    void arrange(long long arr[], int n) {
        // // Your code here
        // long long int i=0,tp;
        // // for(i=0;i<n;i++){
        // //     if(arr[i]!=i)break;
        // // }
        // // tp=i;
        // i=0;
        // long long int p=arr[i],pt,nn=n;
        // nn--;
        // while(1){
        //     if(arr[i]<0)break;
        //     if(arr[i]==0){
        //         arr[i]=-1*p;
        //         i=p;
        //     }
        //     else{
        //         pt=arr[i];
        //         arr[i]=(-1*arr[arr[i]]);
        //         i=pt;
        //     }
        //     // long long int t=arr[arr[i]];
        //     // if(p=)
        //     // p=arr[i];
            
        //     // if(i==0)break;
        // }
        // i=0;
        // for(;i<n;i++)if(i!=0 && arr[i]>0)break;
        // p=arr[i],pt,nn=n;
        // nn--;
        // while(1){
        //     if(arr[i]<0)break;
        //     if(arr[i]==0){
        //         arr[i]=-1*p;
        //         i=p;
        //     }
        //     else{
        //         pt=arr[i];
        //         arr[i]=(-1*arr[arr[i]]);
        //         i=pt;
        //     }
        // }
        // cout<<i<<endl;
        // for(int i=0;i<n;i++)if(arr[i]!=i)arr[i]=-1*arr[i];
        // // cout<<pt;
        // // arr[pt+1]=p;
        
//         //// the main solution 
        for(int i=0;i<n;i++){
            arr[i]+=(arr[arr[i]]%n)*n;
        }
        for(int i=0;i<n;i++)arr[i]/=n;
    }
};
