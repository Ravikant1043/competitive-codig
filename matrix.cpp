#include<iostream>
using namespace std;
struct matrix
{
	int a[2][2];
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
			int sum=0;
			for(int i=0;i<2;i++){
				sum+=A.a[row][i]*B.a[i][col];
			}
			re.a[row][col]=sum;
		}
	}
	return re;
}

matrix expon(matrix A,int b){
	if(b==0) return identity();
	if(b%2==0) return expon(mul(A,A),b/2);
	else return mul(A,expon(A,b-1));
}

int main()
{
	matrix A;
	A.a[0][0]=1,A.a[0][1]=0;
	A.a[1][0]=1,A.a[1][1]=2;
	matrix C=expon(A,8);
	cout<<C.a[0][0]<<" "<<C.a[0][1]<<endl;
	cout<<C.a[1][0]<<" "<<C.a[1][1]<<endl;
	return 0;
}