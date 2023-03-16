/*
https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
*/
#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
	
	int k=1;
	for(int i=0;i+1<nums.size();++i){
		if(nums[i]!=nums[i+1]){
			 nums[k++]=nums[i+1];
		}
	}

	return k;        
}

int main(){
	// vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
	vector<int> nums = {1,1,2};
	cout<<removeDuplicates(nums)<<endl;

	for(auto x:nums){
		cout<<x<<" ";
	}
	cout<<endl;
}	