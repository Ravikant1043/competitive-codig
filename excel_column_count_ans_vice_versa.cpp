
// this code is to convert title to the integer value
int titleToNumber(string c) {
        int ans=0;
        for(auto &it:c){
            int t=it-'A'+1;
            ans=ans*26+t;
        }
        return ans;
    }

// and this is for converting value to the title
string colName (long long int n)
    {
        string ans="";
        while(n>0){
            long long int t=n%26;
            if(t==0){
                ans+='Z';
                n/=26;
                n--;
            }
            else{
                ans+=('A'+t-1);
                n/=26;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
