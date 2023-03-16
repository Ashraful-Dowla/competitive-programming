/*
https://leetcode.com/problems/4sum/description/
*/
#include <bits/stdc++.h>
using namespace std;

map<vector<int>, bool> mp;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
	  
	  int n = nums.size();
	  sort(nums.begin(), nums.end());

	  vector<vector<int>> ans;
	  for(int i=0;i<n;++i){
	  	 for(int j=i+1;j<n;++j){
	  	 	 int lo=j+1, hi=n-1;

	  	 	 while(lo<hi) {
	  	 	    long long sum = nums[i]*1LL+nums[j]*1LL+nums[lo]*1LL+nums[hi]*1LL;

	  	 	    if(sum==target*1LL){
	  	 	    	vector<int> temp;
	  	 	    	temp.push_back(nums[i]);
	  	 	    	temp.push_back(nums[j]);
	  	 	    	temp.push_back(nums[lo]);
	  	 	    	temp.push_back(nums[hi]);

	  	 	    	lo++,hi--;

	  	 	    	if(!mp[temp]){
	  	 	    		ans.push_back(temp);
	  	 	    		mp[temp]=true;
	  	 	    	}
	  	 	    }
	  	 	    else if(sum>target) hi--;
	  	 	    else lo++;
	  	 	 }
	  	 }
	  }

	  return ans;
}

int main(){
	// vector<int> nums = {1,0,-1,0,-2,2};
	vector<int> nums = {2,2,2,2,2};
	int target = 8;

	vector<vector<int>> ans = fourSum(nums, target);

	for(auto x: ans){
		for(auto y: x){
			cout<<y<<" ";
		}
		cout<<endl;
	}
}