/*
https://codeforces.com/contest/1791/problem/A
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

const int MOD=1e9+7;

map<char,bool> mp;
void precompute(){
	string s="codeforces";
	for(int i=0;i<s.size();++i){
		mp[s[i]]=true;
	}
}

void solve(){
	char c;
	cin>>c;
	cout<<(mp[c] ? "YES": "NO")<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;

	precompute();
	while(t--){
	   solve();
	}
}