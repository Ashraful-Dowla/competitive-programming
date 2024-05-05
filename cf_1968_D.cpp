//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1968/problem/D
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

ll resolve(vi &p, vi &a, int x, int k) {

	ll mx = 0, curr = 0;
	int sz = a.size();
	vb vis(sz + 1, false);

	while (!vis[x] && k > 0) {
		vis[x] = true;
		mx = max(mx, curr + k * 1LL * a[x]);
		curr += a[x];
		x = p[x];
		k--;
	}

	return mx;
}

void solve() {

	int n, k, pb, ps;
	cin >> n >> k >> pb >> ps;

	vi p(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
	}

	vi a(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	ll mb = resolve(p, a, pb, k);
	auto ms = resolve(p, a, ps, k);

	if (ms == mb) {
		cout << "Draw" << endl;
	}
	else if (mb > ms) {
		cout << "Bodya" << endl;
	}
	else {
		cout << "Sasha" << endl;
	}

}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}