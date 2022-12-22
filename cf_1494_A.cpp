/*
https://codeforces.com/problemset/problem/1494/A
*/
#include <bits/stdc++.h>
using namespace std;

struct node{
	char a,b,c;
};

vector<char>vec = {'(',')'};

vector<node>pr;

map<char,int>mp = {
	{'(',1},
	{')',-1},
};

void precompute(){
	for(int i=0;i<2;++i){
		for(int j=0;j<2;++j){
			for(int k=0;k<2;++k){
				pr.push_back({vec[i],vec[j],vec[k]});
			}
		}
	}
}

bool isBalanced(string s,int i){
	stack<char>stk;
	for(auto ch:s){
		char c;
		if(ch=='A') c=pr[i].a;
		else if(ch=='B') c=pr[i].b;
		else c=pr[i].c;

		if(mp[c]>0) stk.push(c);
		else {
			if(stk.empty()) return false;
			char tp = stk.top();
			stk.pop();
			if(mp[tp]+mp[c]!=0) return false;
		}
	}

	return stk.empty();
}


int main(){

	precompute();
	int t;
	cin>>t;
	while(t--) {
	    string s;
	    cin>>s;

	    bool isPossible=false;
	    for(int i=0;i<pr.size();++i){
	    	isPossible|=isBalanced(s,i);
	    	if(isPossible) break;
	    }

	    cout<<(isPossible ? "YES": "NO")<<endl;

	}
}