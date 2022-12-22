/*
https://codeforces.com/contest/907/problem/C
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;

	int cnt=0,taken=(1<<26)-1;
	int possible=0;
	for(int i=0;i<n-1;++i){
		char ch;
		string s;
		cin>>ch>>s;
		if(possible==1 && ch!='.') cnt++;
		else if(ch=='!'){
			int curr=0;
			for(int j=0;j<s.size();++j){
				int x = s[j]-'a';
				curr|=(1<<x);
			}
			taken&=curr;
			possible=__builtin_popcount(taken);
		}
		else if(ch=='.' || ch=='?'){
			for(int j=0;j<s.size();++j){
				int x=s[j]-'a';
				if(taken&(1<<x)) taken^=(1<<x);
			}
			possible=__builtin_popcount(taken);
		}
	}

	cout<<cnt<<endl;
}