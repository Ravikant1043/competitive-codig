
class Solution{
    public:
//   this function is for dealing with edge case if one of the victors is empty So it will deal with the other one
    double medi(vector<int>& aa,int size)
    {
        if(size%2==0)return (double)(aa[size/2]+aa[(size/2)-1])/2;
        else return (double)aa[(size/2)];
    }
    double MedianOfArrays(vector<int>& aa, vector<int>& ab)
    {
        int n=aa.size();
        int m=ab.size();
        if(n==0)return medi(ab,m);
        if(m==0)return medi(aa,n);
        if(m<n)return MedianOfArrays(ab,aa);
        
        int l=0,h=n;
        int mid=(n+m+1)/2;
//       here I've applied the binaries search which will go through both vectors i'm fine the median
        while(l<=h){
            
            int m1=(l+h)/2;
            int m2=mid - m1;
            
            int l1 = m1==0 ? INT_MIN : aa[m1-1];
            int l2 = m2==0 ? INT_MIN : ab[m2-1];
            int r1 = m1==n ? INT_MAX : aa[m1];
            int r2 = m2==m ? INT_MAX : ab[m2];
            
            if(l1<=r2 && l2<=r1){
                if((n+m)%2==0){
                    // cout<<l1<<" "<<l2<<" "<<r1<<" "<<r2<<" ";
                    return (min(r1,r2)+max(l1,l2))/2.0;
                }
                else return max(l1,l2);
            }
            else if(l1>r2){
                h=m1-1;
            }
            else l=m1+1;
        }
        return 0.0;
    
    }
