/*
https://codeforces.com/contest/1809/problem/D
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

//debug
#define vec_prnt(v) for(auto x: v) { cout<<x<<" "; } cout<<"\n"

typedef vector<int> vi;

const int N=1e5+10;
const int MOD=1e9+7;

const ll cost = 1e12;

ll last0(string s, vi &pf1, vi &sf0){
	ll res = 1e18;
	int n=s.size();

	for(int i=1;i<=n;++i){
		if(s[i]=='1' && i+1<=n && s[i+1]=='0'){
			res = min(res, cost + (cost+1)*(pf1[i]+sf0[i+1]-2));
		}
		else res = min(res, (cost+1)*(pf1[i]+sf0[i+1]));
	}

	return res;
}

ll first1(string s, vi &pf1, vi &sf0){
	ll res = 1e18;
	int n=s.size();

	for(int i=1;i<=n;++i){
		if(s[i]=='0' && i-1>=1 && s[i-1]=='1'){
			res = min(res, cost+(cost+1)*(sf0[i] + pf1[i-1]-2));
		}
		else res = min(res, (cost+1)*(sf0[i] + pf1[i-1]));
	}

	return res;
}

void solve(){
	string s;
	cin>>s;

	s = "_"+s;
	int n=s.size();
	vi pf1(n+2,0),sf0(n+2,0);

	for(int i=1;i<=n;++i){
		pf1[i] = pf1[i-1] + (s[i]=='1');
	}

	for(int i=n;i>=1;--i){
		sf0[i] = sf0[i+1] + (s[i]=='0');
	}

	ll ans = last0(s,pf1,sf0);
	ans = min(ans, first1(s,pf1,sf0));

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