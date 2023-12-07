//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1907/problem/D
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

bool check(vector<pll>& v, ll k) {

	ll l = 0, r = 0;

	for (int i = 0; i < v.size(); ++i) {
		l = max(l - k, v[i].first);
		r = min(r + k, v[i].second);

		if (l > r) {
			return false;
		}
	}

	return true;
}

void solve() {
	int n;
	cin >> n;

	vector<pll> v;
	for (int i = 0; i < n; ++i) {
		ll l, r;
		cin >> l >> r;
		v.push_back({l, r});
	}

	ll lo = 0, hi = 1e10;

	ll ans = 1e10;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;

		if (check(v, mid)) {
			hi = mid - 1;
			ans = min(ans, mid);
		}
		else {
			lo = mid + 1;
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