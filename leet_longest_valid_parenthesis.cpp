/*
https://leetcode.com/problems/longest-valid-parentheses/description/
*/
#include <bits/stdc++.h>
using namespace std;


int longestValidParentheses(string s){

	stack<int> stk;
		
	int ans=0;
	stk.push(-1);
	for(int i=0;i<s.size();++i){
		if(s[i]=='(') stk.push(i);
		else {
			stk.pop();
			if(stk.empty()) stk.push(i);
			else ans = max(ans, i-stk.top());
		}
	}

	return ans;
}

int main(){

	string s="(()(((()";
	cout<<longestValidParentheses(s)<<endl;
}