/*
https://leetcode.com/problems/two-sum/
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	 map<int, vector<int>> mp;
     for(int i=0;i<nums.size();++i){
     	mp[nums[i]].push_back(i);
     }

     vector<int> ans;
     for(int i=0;i<nums.size();++i){
     	if(mp[nums[i]].size()>1 && target==2*nums[i]){
     		ans.push_back(mp[nums[i]][0]);
     		ans.push_back(mp[nums[i]][1]);
     		break;
     	}
     	else if(mp[target-nums[i]].size()>0 && target!=2*nums[i]){
     		ans.push_back(mp[target-nums[i]][0]);
     		ans.push_back(mp[nums[i]][0]);
     		break;
     	}
     }

     return ans;
}

int main(){
	// vector<int> nums = {2,7,11,15};
	vector<int> nums = {3,3};
	vector<int> ans = twoSum(nums,6);

	for(auto x:ans){
		cout<<x<<" ";
	}
	cout<<endl;
}