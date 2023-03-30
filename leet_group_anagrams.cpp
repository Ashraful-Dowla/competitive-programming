/*
https://leetcode.com/problems/group-anagrams/description/
*/
#include<bits/stdc++.h>
using namespace std;


vector<vector<string>> groupAnagrams(vector<string>& strs) {
    
    int n=strs.size();
    vector<vector<string>> temp(n+2),ans;
    unordered_map<string,int> mp;

    int k=1;
    for(int i=0;i<n;++i){
    	string s = strs[i];
    	sort(s.begin(),s.end());

    	if(!mp[s]) mp[s]=k++;
    	temp[mp[s]].push_back(strs[i]);
    }

    for(auto x: temp){
    	if(x.size()) ans.push_back(x);
    }

    return ans;
}

int main(){
	// vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
	vector<string> strs = {"a"};
	vector<vector<string>> ans = groupAnagrams(strs);

	for(auto v: ans){
		for(auto x: v){
			cout<<x<<" ";
		}
		cout<<endl;
	}
}