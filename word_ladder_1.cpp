class Solution {
public:
    typedef pair<int,string> pp;
    int wordLadderLength(string sw, string tw, vector<string>& wl) {
      
      unordered_set<string>st(wl.begin(),wl.end());
//       here i am using a min heap to get the least integer value string through i  can access the words
      
      priority_queue<pp,vector<pp>,greater<pp>>q;
        
        q.push({1,sw});
//       pushing the starting word
        if(st.find(sw)!=st.end())st.erase(sw);
        
        while(!q.empty()){
            int t=q.top().first;
            string s=q.top().second;
            q.pop();
            
            for(int i=0;i<s.size();i++){
                char p=s[i];
                for(char a='a';a<='z';a++){
                  
//                   changing all the characetrs of the word and iterating through all the formed words
//                   if found in the set just delete it and put in the min heap
                    s[i]=a;
                    if(st.find(s)!=st.end()){
                        q.push({t+1,s});
                        if(s==tw)return t+1;
                        st.erase(s);
                    }
                }
                s[i]=p;
            }
        }
        return 0;
    }
};
