/*
https://leetcode.com/problems/wildcard-matching/
*/
#include <bits/stdc++.h>
using namespace std;

bool solve(int i,int j,string s, string p,vector<vector<int>> &dp){

	if(i==s.size() && j==p.size()) return true;

	if(i==s.size()){
		for(int k=j;k<p.size();++k){
			if(p[k]!='*') return false;
		}
		return true;
	}

	if(j==p.size()) return false;

	if(dp[i][j]!=-1) return dp[i][j];

	bool isPossible=false;
	if(p[j]=='?' || s[i]==p[j]) {
		isPossible|=solve(i+1,j+1, s, p, dp);
	}
	else if(p[j]=='*') {
		isPossible|=solve(i+1,j, s, p, dp);
		isPossible|=solve(i,j+1, s, p, dp);
	}

	return dp[i][j]=isPossible;
}

bool isMatch(string s, string p) {

	vector<vector<int>> dp;
	dp.assign(s.length() + 1, vector<int> (p.length() + 1, -1));
    return solve(0,0,s,p, dp);
}

int main(){
	string s = "bbb";
	string p = "baa";

	cout<<isMatch(s,p)<<endl;
}