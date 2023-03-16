/*
https://leetcode.com/problems/generate-parentheses/description/
*/
#include <bits/stdc++.h>
using namespace std;

vector<string> ss;

void generatePar(int open,int close, string s){

	if(open==0 && close==0){
		ss.push_back(s);
		return ;
	}

	if(open>0){
		s.push_back('(');
		generatePar(open-1,close,s);
		s.pop_back();
	}

	if(close>0 && close>open){
		s.push_back(')');
		generatePar(open,close-1,s);
		s.pop_back();
	}
}


vector<string> generateParenthesis(int n) {
     generatePar(n,n,"");
     return ss; 
}

int main(){
	int n=3;
	vector<string> ans = generateParenthesis(n);

	for(auto x:ans){
		cout<<x<<endl;
	}
}