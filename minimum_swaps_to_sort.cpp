// this functions helps us to find the min no of swaps to sort an array
int minSwaps(vector<int> &nums)
	{
	   vector<pair<int,int>>mp;
	    for(int i=0;i<nums.size();i++)mp.push_back({nums[i],i});
	    int ans=0;
	    sort(mp.begin(),mp.end());
	    for(int i=0;i<mp.size();i++){
	        if(i!=mp[i].second){
	            ans++;
	            swap(mp[i],mp[mp[i].second]);
	            i--;
	        }
	    }
	    return ans;
	}
