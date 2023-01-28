/*
https://codeforces.com/contest/1777/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD=1e9+7;

void solve(){
	int n;
	cin>>n;

	ll sum=1;
	for(int i=1;i<=n;++i){
		sum=(sum*i)%MOD;
	}
	cout<<((((sum*(n-1))%MOD)*n)%MOD)<<endl;	
}

int main(){
	int t;
	cin>>t;

	while(t--) {
	   solve();
	}
}