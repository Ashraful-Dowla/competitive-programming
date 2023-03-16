/*
https://leetcode.com/problems/combination-sum/description/
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> res;
vector<int> temp;
map<vector<int>, bool> mp;

void solve(vector<int> & candidates, int target){
	if(target==0){
		vector<int> tp = temp;
		sort(tp.begin(), tp.end());
		if(!mp[tp]){
			res.push_back(tp);
			mp[tp]=true;
		}
		return;
	}

	for(auto c: candidates){
		if(c<=target) {
		    temp.push_back(c);			
			solve(candidates, target-c);
		    temp.pop_back();			
		}
	}
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	solve(candidates,target);
	return res;
}

int main(){
	vector<int> candidates = {2};
	int target = 1;

	vector<vector<int>> answers = combinationSum(candidates, target);

	for(auto ans: answers){
		for(auto x: ans){
			cout<<x<<" ";
		}
		cout<<endl;
	}
}