//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1933/problem/E
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


void solve() {

	int n;
	cin >> n;

	vector<ll> pf(n + 1, 0);

	for (int i = 1; i <= n; ++i) {
		ll x;
		cin >> x;
		pf[i] = pf[i - 1] + x;
	}

	int q;
	cin >> q;

	while (q--) {
		int l;
		ll u;
		cin >> l >> u;

		u += pf[l - 1];
		auto it = lower_bound(pf.begin() + 1, pf.begin() + n + 1, u);
		int idx = it - pf.begin();

		if (pf[idx] - u > u - pf[idx - 1]) {
			idx--;
		}

		idx = max(l, idx);
		idx = min(n, idx);

		cout << idx << " ";

	}
	cout << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}