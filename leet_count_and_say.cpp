/*
https://leetcode.com/problems/count-and-say/description/
*/
#include <bits/stdc++.h>
using namespace std;


string solve(int n){
	if(n==1) return "1";

	string s = solve(n-1);
	int cnt=1;

	s+="_";
	string res="";
	for(int i=0;i+1<s.size();++i){
		if(s[i]==s[i+1]) cnt++;
		else {
			res+=to_string(cnt);
			res.push_back(s[i]);
			cnt=1;
		}
	}

	return res;
}

string countAndSay(int n) {
	return solve(n);
}

int main(){
	int n=5;
	cout<<countAndSay(n)<<endl;
}