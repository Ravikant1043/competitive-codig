// use the recurdion in a ways that swaps the numbers one by one

class Solution {
public:
    int count=0;
    void check(vector<int>&ans,int i){
        if(i==ans.size()){
                count++;
                return;
            }
        for(int j=i;j<ans.size();j++){
            swap(ans[i],ans[j]);
            if((ans[i]%(i+1)==0) || ((i+1)%ans[i]==0))
                check(ans,i+1);
            swap(ans[i],ans[j]);
        }
    }
    int countArrangement(int n) {
        vector<int>ans(n,0);
        for(int i=1;i<=n;i++)ans[i-1]=i;
        check(ans,0);
        return count;
    }
};
