/*
https://leetcode.com/problems/goal-parser-interpretation/
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
	string s,result;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='(' && s[i+1] == ')') result.push_back('o');
		else if(s[i]=='(' && s[i+1]=='a' && s[i+2] =='l' && s[i+3] == ')'){
			result.push_back('a');
			result.push_back('l');
		}
		else if(s[i]=='G') result.push_back('G');
	}
	cout<<result<<endl;
}