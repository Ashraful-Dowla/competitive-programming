/*
https://codeforces.com/contest/1766/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e7+10;
vector<ll> res;

void calculate(){
	for(int i=1;i<=N;i*=10){
		for(int j=1;j<10;++j){
			res.push_back(i*1LL*j);
		}
	}
}

void solve(){
	int n;
	cin>>n;

	auto it = lower_bound(res.begin(),res.end(),n);

	int ans = it-res.begin();
	cout<<ans+(*it==n)<<endl;
}

int main(){
	int t;
	cin>>t;

	calculate();
	while(t--) {
	    solve();
	}
}