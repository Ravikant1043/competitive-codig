#include<bits/stdc++.h>
using namespace std;

int be(int a,int b){
    if(b==0) return 1;
    if(b%2==0) 
        return be(a*a,b/2);
    else{
       return a*be(a,b-1) ;
    }

}

void printpermutation(string &s,int fr[],string d,int i){
    if(i==s.size()){
        cout<<d<<endl;
        return ;
    }
    for(int id=0;id<s.size();id++){
        if(fr[id]==0){
            fr[id]=1;
            printpermutation(s,fr,d+s[id],i+1);
            fr[id]=0;
        }
    }
}
int main(){
    string s;
    cin>>s;
    int n=s.size();
    string d="";
    int i=0;
    int fre[n]={0};
    printpermutation(s,fre,d,i);
    return 0;
}
