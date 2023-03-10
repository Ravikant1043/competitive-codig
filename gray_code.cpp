class Solution {
public:
  
//   // this function generates the gray code by calling the recursion of its previous one
  
    vector<int> grayCode(int n) {
        if(n==1)return {0,1};
        vector<int>ans=grayCode(n-1);    ///////////// recursion call of the previous number
      
        for(int i=ans.size()-1;i>=0;i--){
            ans.push_back(ans[i]|(1<<(n-1)));
        }
//       ////////////// adding the numbers from its reverse by just making them bitwise or with the 1 leftshift to n-1 
      
        return ans;
    }
};
