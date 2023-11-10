// bool help(string s,string ss,int i,unordered_map<char,int>mp){
    //     int t=s.size()-1;
    //     char p=s[t];
    //     for(int j=i;j<ss.size();j++){
    //         if(ss[i]=='D'){
    //             if(mp[(p-'0')-1 +'0']==0)
    //             s+=
    //         }
    //     }
    // }
    string printMinNumberForPattern(string ss){
        
        string ans;
        stack<int>s;
        int n=1;
        for(int i=0;i<ss.size();i++){
            s.push(n);
            n++;
            if(ss[i]=='I'){
                while(!s.empty()){
                    ans+=(s.top()+'0');
                    s.pop();
                }
            }
        }
        s.push(n);
        n++;
        while(!s.empty()){
            ans+=(s.top()+'0');
            s.pop();
        }
        return ans;
        
        // code here 
        // stirng s;
        // unordered_map<char,int>mp;
        // for(char i='1';i<='9';i++)mp[i]=1;
        // for(char i='1';i<='9';i++){
        //     s+=i;
        //     mp[i]=0;
        //     if(help(s,ss,0,mp))return s;
        //     mp[i]=1;
        //     s.pop_back();
        // }
        // return "";
    }
