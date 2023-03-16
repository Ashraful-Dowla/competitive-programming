/*
https://leetcode.com/problems/search-insert-position/description/
*/
#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& nums, int target) {

	int n = nums.size();
    auto it = lower_bound(nums.begin(), nums.end(), target);

    if(it==nums.end()) return n;

    return it-nums.begin();
}

int main(){
	vector<int> nums = {1,3,5,6};
	int target = 7;

	cout<<searchInsert(nums, target);
}