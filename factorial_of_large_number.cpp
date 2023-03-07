class Solution {
private:
    void multipp(vector<int>& t,int n){
        int ca=0;
        int i=0;
        while(i<t.size()){
            int v=t[i]*n+ca;
            t[i]=v%10;
            // cout<<t[i]<<" .";
            ca=v/10;
            i++;
        }
        while(ca!=0){
            t.push_back(ca%10);
            // cout<<t[1]<<" ;;";
            ca/=10;
        }
    }
  
 public:
    vector<int> factorial(int n){
        // code here
        vector<int>t;
        t.push_back(1);
        for(int i=2;i<=n;i++){
            // multiply(tail,i)
            multipp(t,i);
        }
        reverse(t.begin(),t.end());
        return t;
    }
};
