/*
https://leetcode.com/problems/combination-sum-ii/description/
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> res;
vector<int> temp;
map<vector<int>, bool> mp;

void solve(int k,vector<int> & candidates, int target){

	if(target==0){
		if(!mp[temp]) {
			mp[temp]=true;
			res.push_back(temp);
		}

		return ;
	}

	for(int i=k;i<candidates.size();++i){
		if(i>k && candidates[i]==candidates[i-1]) continue;
		if(candidates[i]<=target){
			temp.push_back(candidates[i]);
			solve(i+1,candidates, target-candidates[i]);
			temp.pop_back();
		}
	}
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

	sort(candidates.begin(),candidates.end());
	solve(0,candidates, target);
    return res;
}

int main(){
	vector<int> candidates = {10,1,2,7,6,1,5};
	int target = 8;

	vector<vector<int>> answers = combinationSum2(candidates, target);

	for(auto ans: answers){
		for(auto x: ans){
			cout<<x<<" ";
		}
		cout<<endl;
	}
}
