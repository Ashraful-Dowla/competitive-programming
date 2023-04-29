//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1810/problem/D
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll> 
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
	int n;
	cin>>n;

	vll ans;
	ll l=1, r=1e18;
	for(int i=0;i<n;++i){
		ll t,a,b,n;
		cin>>t;

		if(t==1){
			cin>>a>>b>>n;
			ll L = (n-2)*(a-b) + a + 1;
			ll R = (n-1)*(a-b) + a;

			if(n==1) L=1,R=a;

			if(R<l || L>r) ans.push_back(0);
			else {
				ans.push_back(1);
				l = max(l,L);
				r = min(r,R);
			}
		}
		else {
			cin>>a>>b;

			double dl = max(1.0, 1.0 + (1.0*(l-a))/(a-b));
			double dr = max(1.0, 1.0 + (1.0*(r-a))/(a-b));

			ll d = ceil(dl);
			if(ceil(dr)!=ceil(dl)) ans.push_back(-1);
			else ans.push_back(d);
		}
	}

	vec_prnt(ans);
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}