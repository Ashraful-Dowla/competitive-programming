#include <bits/stdc++.h>
using namespace std;

vector<int> NGE(vector<int>& nums) {
	vector<int>nge(nums.size());
	stack<int>stk,temp;

	for(int i=0;i<nums.size();i++){
		while(!stk.empty() && nums[i] > nums[stk.top()]){
			nge[stk.top()] = i;
			stk.pop();
		}
		stk.push(i);
	}

	for(int i=nums.size()-1;i>=0;i--){
		temp.push(i);
	}

	while(!temp.empty() && !stk.empty()){
		if(nums[stk.top()]<nums[temp.top()]){
			nge[stk.top()] = temp.top();
			stk.pop();
		}
		else temp.pop();
	}

	while(!stk.empty()){
		nge[stk.top()] = -1;
		stk.pop();
	}

	for(int i=0;i<nums.size();i++){
		if(nge[i]!=-1) nge[i] = nums[nge[i]];
	}

	for(int i=0;i<nums.size();i++){
		cout<<nge[i]<<" ";
	}

	return nge;
}

int main(){
	// vector<int>v = {1,2,3,4,3};
	vector<int>v = {1,2,1};

	vector<int>nge = NGE(v);
}