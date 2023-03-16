/*
https://leetcode.com/problems/next-permutation/description/
*/
#include <bits/stdc++.h>
using namespace std;

void prnt(vector<int>& nums){
	for(auto x: nums){
	   	cout<<x<<" ";
	}
	cout<<endl;
}
void nextPermutation(vector<int>& nums) {

	bool ok=true;
	while(next_permutation(nums.begin(),nums.end())) {
		ok=false;
	    prnt(nums);
	    break;
	}

	if(ok) prnt(nums);
}

int main(){
	vector<int> nums = {3,2,1};
	nextPermutation(nums);
}