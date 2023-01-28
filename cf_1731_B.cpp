/*
https://codeforces.com/contest/1731/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD=1e9+7;

void solve(){
	ll n;
	cin>>n;

	ll nn = (n*(n+2))%MOD;
	
	ll sum = (n*(2*n+1))%MOD;
	sum = (sum + (2*nn)%MOD)%MOD;
	sum = (sum - (6*n)%MOD + MOD)%MOD;

	sum = (sum*(n+1))%MOD;
	sum = (sum * 166666668)%MOD;

	cout<<(2022*sum)%MOD<<endl;

}

int main(){
	int t;
	cin>>t;

	while(t--) {
	    solve();
	}
}