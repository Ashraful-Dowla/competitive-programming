/*
https://leetcode.com/problems/3sum-closest/description/
*/
#include <bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    int n = nums.size();

   	sort(nums.begin(), nums.end());

   	vector<int> res;
   	for(int i=0;i<n;++i){
   		int lo=i+1, hi=n-1;

   		while(lo<hi) {
   		    int sum = nums[i] + nums[lo] + nums[hi];

   		    if(sum==target){
   		    	lo++,hi--;
   		    }
   		    else if(sum>target) hi--;
   		    else lo++;

   		    res.push_back(sum);
   		}
   	}

   	int mn=INT_MAX, ans;
    for(auto x: res){
    	int diff = abs(target-x);
    	if(diff<mn){
    		mn = diff;
    		ans=x;
    	} 
    }
   
    return ans;
}

int main(){
	// vector<int> nums = {-1,2,1,-4};
	vector<int> nums = {0,0,0};
	int target = 1;

	cout<<threeSumClosest(nums, target)<<endl;
}