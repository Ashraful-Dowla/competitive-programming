/*
https://codeforces.com/contest/1798/problem/C
*/

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define vi vector<int>
#define pii pair<int,int>  

//debug
#define vec_prnt(v) for(auto x: v) { cout<<x<<" "; } cout<<"\n"

const int N=1e5+10;
const int MOD=1e9+7;

ll __lcm(ll a, ll b){
	return (a*b)/__gcd(a,b);
}

void solve(){
	int n;
	cin>>n;	

	ll a[n],b[n];
	for(int i=0;i<n;++i){
		cin>>a[i]>>b[i];
	}

	ll lcm=1,gcd=0;
	int ans=1;

	for(int i=0;i<n;++i){
		gcd = __gcd(gcd, a[i]*b[i]);
		lcm = __lcm(lcm, b[i]);

		if(gcd%lcm){
			ans++;
			gcd = a[i]*b[i];
			lcm = b[i];
		}
	}

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