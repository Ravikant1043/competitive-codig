
// this function is for getting the elements which are lower than the mid elements of the function called
int count(int mat[MAX][MAX], int n, int k){
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=upper_bound(mat[i],mat[i]+n,k)-mat[i];
    }
    return ans;
}


int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  int l=mat[0][0];
  int h=mat[n-1][n-1];
  //  binary search for getting the element specified for the given condition
  while(l<=h){
      int mid=(l+h)/2;
      int c=count(mat,n,mid);
      if(c<k){
          l=mid+1;
      }
      else{
          h=mid-1;
      }
  }
  return l;
}
