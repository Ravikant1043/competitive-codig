#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    ll t=8878499900;
    string tt=to_string(t);
    
    cout<<t%9<<"\n";
    int c=0;
    for(auto &it:tt){
        c=c*10 + it-'0';
        c%=9;
    }
    cout<<c;
}

for a single character/integer in a number we are calculating its mod and just adding it to the new number and again computing the same
