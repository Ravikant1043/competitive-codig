#include <bits/stdc++.h>
using namespace std;
void FastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

static bool cmp(pair<int,int>&addd,pair<int,int>&b){
    return addd.second<b.second;
}


int main() {
    FastIO();
    int n;
    cin>>n;
    vector<int>read(n,0);
    for(int i=0;i<n;i++)cin>>read[i];
    vector<int>ans(n+1,0);
    
    // no of quereis for updation of the array
    int t;
    cin>>t;
    while(t--){
        int a,b,c;  // range for updation of the array
        cin>>a>>b;
        cin>>c;     // value which needed to be added
        ans[a]=c;
        ans[b+1]=-c;
    }
    for(int i=1;i<=n;i++)ans[i]+=ans[i-1];


    // printing the updated array

    for(int i=0;i<n;i++)cout<<ans[i]+read[i]<<" ";

    return 0;
}




// input
// 8
// 2 4 7 5 1 3 8 9
// 2
// 0 2 1
// 4 6 7


// output
// 3 5 8 5 8 10 15 9 
