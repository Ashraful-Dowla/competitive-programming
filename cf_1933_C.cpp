//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1933/problem/C
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

const int N = 1e5 + 10;
const int MOD = 1e9 + 7;

ll pw(ll a, ll n) {
	ll res = 1;
	for (int i = 0; i < n; ++i) {
		res *= a;
	}
	return res;
}

void solve() {

	ll a, b, l;
	cin >> a >> b >> l;

	ll p = log2(l) / log2(a) + 1;
	ll q = log2(l) / log2(b) + 1;

	unordered_map<ll, bool> taken;
	ll ans = 0;

	for (ll x = 0; x <= p; ++x) {
		for (ll y = 0; y <= q; ++y) {
			ll aa = pw(a, x);
			ll bb = pw(b, y);
			ll k = l / (aa * bb);
			if (l % (aa * bb) == 0 && !taken[k]) {
				ans++;
				taken[k] = true;
			}
		}
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