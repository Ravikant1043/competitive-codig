class Solution{
public:

    // void remove(string &s,bool t){
    //     // if()
    //     string ss;
    //     int i;
    //     for(i=0;i<s.size()+1;i++){
    //         if(s[i]==s[i+1]){
    //             break;
    //         }
    //         ss+=s[i];
    //     }
    //     ss+=s.substr(i+1);
    //     s=ss;
    // }
  
  
  
    bool check(string s){
        if(s=="")return false;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1])return true;
        }
        return false;
    }
    string rremove(string s){
        // bool t=true;
      
//       here i am checking the next and previous element which is not maching if matching neglect it or add it
        string ss="";
        int i;
        for(i=0;i<s.size();i++){
            if(i==0)
                {if( s[i]!=s[i+1]){
                    ss+=s[i];
                }}
            else if(i==s.size()-1){
                if(s[i]!=s[i-1])ss+=s[i];
            }
            else {
                if(s[i]==s[i-1] || s[i]==s[i+1])ss=ss;
                else ss+=s[i];
            }
            
            // cout<<ss<<" ";
        }
        // return ss;
        
        if(check(ss))return rremove(ss);
        return ss;
        // return rremove(s);
        // if()
    }
};
