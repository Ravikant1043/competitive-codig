#include<bits/stdc++.h>
using namespace std;

// this segment tree is for finding the maximum of the array between the queries
class segmenttree{
    private:
    vector<int>tree,tt;

    public:
    // constructor used for declaration of the array/vector with the provided vector and its size
    segmenttree(vector<int>&a,int n){
        for(int i=0;i<4*n;i++){
            tree.push_back(0);
        }
        tt=a;
        // for(auto &it:tree)cout<<it<<" ";
        // cout<<"hello"<<"\n";
    }

// this function is used for building the segment tree which can be accessed at any time
    void build(int node,int start,int end){
        if(start==end){
            tree[node]=tt[start];
            return;
        }
        int mid=(start+end)/2;
        build(node*2,start,mid);
        build(node*2+1,mid+1,end);
        tree[node]=max(tree[node*2],tree[node*2+1]);

        // if anychanges needed as per the question change the last line as per the requirements in both "update" and the "build" function
    }

//  to get the maximum between the l and r range
    int query(int node ,int l,int r,int start,int end){
        if(start>r || end<l)return INT_MIN;
        if(start==end || (l<=start && end<=r))return tree[node];
        int mid=(start+end)/2;
        int left=query(node*2,l,r,start,mid);
        int right=query(node*2+1,l,r,mid+1,end);
        return max(left,right);
    }

// update function for updating the queries as per need
    void update(int node,int start,int end,int pos,int val){
        if(start==end && start==pos){
            tree[node]=val;
            tt[start]=val;
            return;
        }
        int mid=(start+end)/2;
        if(pos<=mid && pos>=start){
            update(node*2 ,start,mid,pos,val);
        }
        else update(node*2+1,mid+1,end,pos,val);
        tree[node]=max(tree[node*2],tree[node*2+1]);
    }

// just for displaying the vectors
    void display(){
        // cout<<"display Function\n";
        // display function as to check anything as you needed
        for(auto &it:tt)cout<<it<<" ";
        cout<<"\n";
    }

};

int main(){
    vector<int>t;
    for(int i=0;i<5;i++){
        int a;
        cin>>a;
        t.push_back(a);
    }
    segmenttree st(t,5);
    st.build(1,0,4);
    st.display();
    cout<<st.query(1,1,3,0,4)<<"\n";
    // cout<<st.query(1,3,4,0,4)<<"\n";

    st.update(1,0,4,2,101);
    cout<<st.query(1,1,3,0,4)<<"\n";
    st.display();
}
