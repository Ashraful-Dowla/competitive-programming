//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1931/problem/D
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
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>


#define pb push_back
#define eb emplace_back
#define all(c) (c).begin(),(c).end()

//debug
#define vec_prnt(v) for(auto x: v) { cout<<x<<" "; } cout<<"\n"
#define prnt1(x) cout<<x<<endl
#define prnt2(x,y) cout<<x<<" "<<y<<endl

const int N = 2e5 + 10;
const ll INF = 1e9 + 7;
const int MOD = 1e9 + 7;


void solve() {

	int n;
	ll x, y;

	cin >> n >> x >> y;

	ll a[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	map<pll, ll> mp;

	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ll xx = a[i] % x, yy = a[i] % y;
		ans += mp[ {(x - xx) % x, yy}];
		mp[ {xx, yy}]++;
	}

	cout << ans << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}