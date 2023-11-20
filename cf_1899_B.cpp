//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1899/problem/B
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
const int MOD = 1e9 + 7;

vector<ll> vec(N), pf(N);

void solve() {

	ll n;
	cin >> n;

	for (ll i = 1; i <= n; ++i) {
		cin >> vec[i];
	}

	for (ll i = 1; i <= n; ++i) {
		pf[i] = pf[i - 1] + vec[i];
	}

	ll ans = 0;

	for (ll k = 1; k <= n; ++k) {
		ll mx = 0, mn = 1e15;
		if (n % k) continue;
		for (ll i = k; i <= n; i += k) {
			mx = max(mx, pf[i] - pf[i - k]);
			mn = min(mn, pf[i] - pf[i - k]);
		}
		ans = max(ans, mx - mn);
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