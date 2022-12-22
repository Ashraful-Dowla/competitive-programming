/*
https://codeforces.com/contest/1767/problem/D
*/
#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int cnt_1=0,cnt_0=0;
	for(int i=0;i<n;++i){
		if(s[i]=='1') cnt_1++;
		else cnt_0++;
	}

	int st = 1<<cnt_1;
	int nd = (1<<n) - (1<<cnt_0)+1;
	for(int i=st;i<=nd;++i){
		cout<<i<<" ";
	}
	cout<<endl;
}
int main(){
	solve();
}