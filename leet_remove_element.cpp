/*
https://leetcode.com/problems/remove-element/description/
*/
#include <bits/stdc++.h>
using namespace std;

int removeElement(vector<int>& nums, int val) {
	sort(nums.begin(),nums.end());

	int lo=0, hi=nums.size()-1;
	int k=0;

	while(lo<=hi) {
	    if(nums[lo]!=val){
	    	 k++,lo++;
	    }
	    else if(nums[lo]==val && nums[hi]!=val) {
	    	nums[lo++]=nums[hi--];
	    	k++;
	    }
	    else hi--;
	}

	return k;

}

int main(){

	vector<int> nums = {3,2,2,3};
	// vector<int> nums = {0,1,2,2,3,0,4,2};
	int val = 3;
	int k = removeElement(nums, val);

	for(int i=0;i<k;++i){
		cout<<nums[i]<<" ";
	}
}