/*
https://codeforces.com/contest/1770/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,k;
	cin>>n>>k;

	int l=1,r=n, nxt=1;

	while(l<=r){
		nxt=1-nxt; //nxt^=1
		cout<<(nxt ? l++: r--)<<" ";
	}
	cout<<endl;
	
}

int main(){
	int t;
	cin>>t;

	while(t--) {
	    solve();
	}
}