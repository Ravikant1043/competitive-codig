
class Solution{
    public:
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0])return a[1]<b[1];
        return a[0]<b[0];
    }
  
  
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        sort(range.begin(),range.end(),cmp);
        vector<pair<int,int>>ans;
        int i=0;
        int j=1;
//       function for merging the range function to get a optimal range values;
        while(j<n){
            if(range[j-1][1]<range[j][0]){
                ans.push_back({range[i][0],range[j-1][1]});
                i=j;
            }
            else {
                range[j][1]=max(range[j-1][1],range[j][1]);
            }
            j++;
        }
        ans.push_back({range[i][0],range[j-1][1]});
        n=ans.size();
        vector<int>aa;
//       iterating through the queries function for getting the result as per the need
        for(auto &it:queries){
            int s=0;
            int i=0;
            for(;i<n;i++){
              
//               check the length of the particular pair that a element which we are searching can exist in this length or not 
//               if element exist then break and give the output as the sum of the first index and the requires one;
                if(s+ans[i].second-ans[i].first+1>=it)break;
                s+=ans[i].second-ans[i].first+1;
            }
//           if index is out of bound the print -1
            if(i>=n){
                aa.push_back(-1);
                continue;
            }
//           adding the element which we found as per given in the queries
            s=it-s-1;
            aa.push_back(ans[i].first+s);
        }
        return aa;
    } 
};
