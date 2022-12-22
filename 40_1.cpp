/*
https://leetcode.com/problems/next-greater-element-i/
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> NGE(vector<int>& nums1, vector<int>& nums2) {
	vector<int>nge(nums2.size());
	stack<int>stk;
	for(int i=0;i<nums2.size();i++){
		while(!stk.empty() && nums2[i] > nums2[stk.top()]) {
			nge[stk.top()] = i;
			stk.pop();
		}
		stk.push(i);
	}

	while(!stk.empty()){
		nge[stk.top()] = -1;
		stk.pop();
	}

	int N=1e4+10;
	vector<int>vec(N);
	for(int i=0;i<nums2.size();i++){
		vec[nums2[i]] = (nge[i] == -1 ? -1: nums2[nge[i]]);	
	}
	for(int i=0;i<nums1.size();i++){
		if(vec[nums1[i]]==0) nums1[i] = -1;
		else nums1[i] = vec[nums1[i]];
	}
	return vec;
}

int main(){
	// vector<int> nums1 = {4,1,2};
	vector<int> nums1 = {2,4};
	// vector<int> nums2 = {1,3,4,2};
	vector<int> nums2 = {1,2,3,4};

	vector<int> nge = NGE(nums1,nums2);
}