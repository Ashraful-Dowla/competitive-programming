/*
https://codeforces.com/contest/1793/problem/A
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

// n = (m+1)*q + r

void solve(){
	ll a,b,n,m;
	cin>>a>>b;
	cin>>n>>m;

	ll q = n/(m+1);
	ll r = n-q*(m+1);

	ll ans = q*min(a*m,b*(m+1)) + r*min(a,b);
	cout<<ans<<endl;
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}