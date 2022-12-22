/*
https://leetcode.com/problems/contains-duplicate/
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	map<long long,int>mp;
	vector<int>nums = {1, 2, 4, 4};
	bool check = false;
	for(int i=0;i<nums.size();i++){
		long long val = nums[i];
		mp[val]++;
		if(mp[val]>1) check = true;
	}

	cout<<check<<endl;
}