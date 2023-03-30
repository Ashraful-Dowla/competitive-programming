/*
https://leetcode.com/problems/jump-game-ii/description/
*/
#include <bits/stdc++.h>
using namespace std;

int dp[100005];

int solve(int i, vector<int> &nums){

	if(i+1==nums.size()) return 0;
	if(dp[i]!=-1) return dp[i];

	int ans=1e5;
	for(int j=1;j<=nums[i];++j){
		if(i+j<nums.size()){
			ans = min(ans,solve(i+j,nums)+1);
		}
	}

	return dp[i]=ans;
}


int jump(vector<int>& nums) {
	memset(dp, -1, sizeof(dp));
    return solve(0,nums);
}

int main(){

	// vector<int> nums = {2,3,1,1,4};
	vector<int> nums = {2,3,0,1,4};
	cout<<jump(nums)<<endl;
}