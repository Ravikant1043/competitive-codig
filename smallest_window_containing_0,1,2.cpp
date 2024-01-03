class Solution {
  public:
    int smallestSubstring(string S) {
        int ans=1e9;
        // unordered_map<int,int>mp;
        int mp[3]={0,0,0};
        int j=0,i=0,n=S.size();
        int c=0;
        while(j<n){
            // mp[S[j]-'0']++;
            // while(mp.size()==3){
            //     ans=min(ans,j-i+1);
            //     mp[S[i]-'0']--;
            //     if(mp[S[i]-'0']==0)mp.erase(S[i]-'0');
            //     i++;
            // }
            // j++;
            int t=S[j]-'0';
            if(mp[t]==0)c++;
            mp[t]++;
            while(c==3){
                ans=min(ans,j-i+1);
                mp[S[i]-'0']--;
                if(mp[S[i]-'0']==0)c--;
                i++;
            }
            j++;
        }
        return ans==1e9?-1:ans;
    }
};
