#include <bits/stdc++.h>
using namespace std;

map<char,int> precendence = {
	{'^',3},
	{'/',2},
	{'*',2},
	{'+',1},
	{'-',1}
};

bool char_check(char c){
	return (c>='a'&&c<='z') || (c>='A'&&c<='Z'); 
}

int prec_check(char c){
	return precendence[c]==0 ? -1: precendence[c]; 
}

string infix_to_postfix(string s){
	stack<char> stk;
	string res;

	for(int i=0;i<s.size();++i){
		if(char_check(s[i])){
			res.push_back(s[i]);
		}
		else if(s[i]=='('){
			stk.push(s[i]);
		}
		else if(s[i]==')'){
			while(!stk.empty() && stk.top()!='(') {
			    res.push_back(stk.top());
			    stk.pop();
			}
			if(!stk.empty()){
				stk.pop();
			}
		}
		else {
			while(!stk.empty() && prec_check(stk.top())>prec_check(s[i])){
				res.push_back(stk.top());
				stk.pop();
			}
			stk.push(s[i]);
		}
	}

	while(!stk.empty()){
		res.push_back(stk.top());
		stk.pop();
	}

	return res;
}

int main(){
	string s="(a-b/c)*(a/k-l)";
	reverse(s.begin(),s.end());
	for(int i=0;i<s.size();++i){
		if(s[i]=='(') s[i]=')';
		else if(s[i]==')') s[i]='(';
	}
	s= infix_to_postfix(s);
	reverse(s.begin(),s.end());
	cout<<s<<endl;
}