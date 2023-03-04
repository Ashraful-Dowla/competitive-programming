/*
https://codeforces.com/contest/1786/problem/B
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

//debug
#define vec_prnt(v) for(auto x: v) { cout<<x<<" "; } cout<<"\n"

const int N=1e5+10;
const int MOD=1e9+7;

void solve(){
	int n,w,h;
	cin>>n>>w>>h;


	vector<ll> a,b;
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		a.push_back(x);
	}

	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		b.push_back(x);
	}

	ll l=-1e9,r=1e9;
	for(int i=0;i<n;++i){
		l = max(l, a[i]-w-b[i]+h);
		r = min(r, a[i]+w-b[i]-h);
	}

	cout<<(l<=r ? "YES": "NO")<<endl;
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}