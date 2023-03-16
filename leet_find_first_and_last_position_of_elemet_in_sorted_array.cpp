/*
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
	
	int n = nums.size();
	vector<int> ans(2,-1);

	if(n==0) return ans;

	auto it = lower_bound(nums.begin(),nums.end(),target);
	if(it!=nums.end() && *it==target) ans[0] = it-nums.begin();
	else return ans;

	it = upper_bound(nums.begin(),nums.end(),target);

	if(it==nums.end()) ans[1]=n-1;
	else ans[1] = it-nums.begin()-1;

	return ans;
}

int main(){
	vector<int> nums = {2,2};
	int target = 3;

	vector<int> ans = searchRange(nums,target);

	for(auto x: ans){
		cout<<x<<" ";
	}
	cout<<endl;
}