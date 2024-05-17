//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1946/problem/B
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
const ll MOD = 1e9 + 7;

ll binaryExp(ll a, int b) {

	ll res = 1;
	while (b) {
		if (b & 1) {
			res = (res * a) % MOD;
		}
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}

void solve() {

	int n, k;
	cin >> n >> k;

	vector<ll> v(n);

	ll res = 0;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		res = (res + v[i] + MOD) % MOD;
	}

	ll sum = v[0], best = v[0];
	for (int i = 1; i < n; ++i) {
		sum = max(v[i], sum + v[i]);
		best = max(best, sum);
	}

	ll p = (binaryExp(2, k) - 1) % MOD;
	best = (max(0LL, best)) % MOD;
	ll ans = (res + best * p) % MOD;

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