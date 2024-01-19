typedef long long ll;
class Solution {
    private:
    int mod=1e9+7;
    struct matrix
    {
    	ll a[2][2];
    };
    matrix identity(){
    	matrix id;
    	id.a[0][0]=1,id.a[0][1]=0;
    	id.a[1][0]=0,id.a[1][1]=1;
    	return id;
    }
    
    matrix mul(matrix A,matrix B){
    	matrix re;
    	for(int row=0;row<2;row++){
    		for(int col=0;col<2;col++){
    			ll sum=0;
    			for(int i=0;i<2;i++){
    				sum=(sum+(A.a[row][i]%mod*B.a[i][col]%mod)%mod)%mod;
    			}
    			re.a[row][col]=sum%mod;
    		}
    	}
    	return re;
    }
    
    matrix expon(matrix A,long long int b){
    	if(b==0) return identity();
    	if(b%2==0) return expon(mul(A,A),b/2);
    	else return mul(A,expon(A,b-1));
    }
  public:
    int countStrings(long long int N) {
        matrix A;
    	A.a[0][0]=1,A.a[0][1]=1;
    	A.a[1][0]=1,A.a[1][1]=0;
    	matrix C=expon(A,N+1);
    	return C.a[0][0];
    }
};
