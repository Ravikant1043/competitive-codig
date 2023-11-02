class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>abc[n],indeg(n,0);
        vector<int>ans;
        for(auto i:edges){
            abc[i[0]].push_back(i[1]);
            abc[i[1]].push_back(i[0]);
            indeg[i[0]]++;
            indeg[i[1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==1)q.push(i),indeg[i]--;
        }
        while(!q.empty()){
            int n=q.size();
            ans.clear();
            for(int i=0;i<n;i++){
                int t=q.front();
                q.pop();
                ans.push_back(t);
                for(auto &it:abc[t]){
                    indeg[it]--;
                    if(indeg[it]==1)q.push(it);
                }
            }
        }
        if(n==1)ans.push_back(0);
        return ans;
    }
};

/*
  just going back from leaf to the top one that's it
*/
