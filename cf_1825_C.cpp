//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1825/problem/C
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define ll long long
#define ld long double
#define vi vector<int> 
#define vs vector<string>
#define vb vector<bool> 
#define pii pair<int,int>
#define pll pair<ll,ll>


#define pb push_back
#define all(c) (c).begin(),(c).end()

//debug
#define vec_prnt(v) for(auto x: v) { cout<<x<<" "; } cout<<"\n"
#define prnt1(x) cout<<x<<endl
#define prnt2(x,y) cout<<x<<" "<<y<<endl

const int N=1e5+10;
const int MOD=1e9+7;

void solve(){
	int n, m;
	cin>>n>>m;

	vi vec(m+2, 1), pf(m+2, 0), sf(m+2, 0);
	int l=0, r=0, p=0;

	for(int i=0;i<n;++i){
		int x;
		cin>>x;

		if(x==-1) l++;
		else if(x==-2) r++;
		else {
			if(vec[x]==1) p++;
			vec[x]=0;
		}
	}

	for(int i=1;i<=m;++i){
		pf[i] = pf[i-1] + vec[i];
	}

	for(int i=m;i>=1;--i){
		sf[i] = sf[i+1] + vec[i];
	}

	int ans=max(p + l, p + r);
	for(int i=1;i<=m;++i){
		if(vec[i]==0){
			ans = max(ans, p + min(pf[i], l) + min(sf[i], r)); 
		}
	}

	prnt1(min(ans, m));	
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}