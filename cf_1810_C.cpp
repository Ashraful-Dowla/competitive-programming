//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1810/problem/C
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
	int n,c,d;
	cin>>n>>c>>d;

	vi vec(n);

	for(int i=0;i<n;++i){
		cin>>vec[i];
	}

	sort(all(vec));

	ll ans=0;
	if(vec[0]!=1){
		ans+=d;
		vec.pb(1);
		n++;
	}

	sort(all(vec));
	vec.erase(unique(all(vec)), vec.end());

	int duplicate = n-vec.size();
	ans+=(duplicate*1LL*c);
	n=vec.size();

	ll sum=1e18;
	for(int i=0;i<n;++i){
		ll ms = vec[i]-i-1;
		sum = min(sum, ms*d + c*1LL*(n-i-1));
	}

	prnt1(ans+sum);
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}