/*
https://codeforces.com/contest/1790/problem/A
*/
#include<bits/stdc++.h>
using namespace std;

const int MOD=1e9+07;

void solve(){
	string pi="314159265358979323846264338327";
	string s;
	cin>>s;

	int i=0,j=0;
	while(i<s.size() && s[i]==pi[j]){
		i++,++j;
	}

	cout<<i<<endl;
}

int main(){
	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}