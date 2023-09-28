//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1873/problem/F
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


ll can(vector<ll>& pf, int l, int r, int len, ll k) {

	ll sum = 0;
	for (int i = l + len - 1; i <= r; ++i) {
		ll res = pf[i] - pf[i - len];
		if (res > k) continue;
		sum = max(sum, res);
	}

	return sum;
}

void solve() {

	int n;
	ll k;
	cin >> n >> k;

	vector<ll>a(n + 1), h(n + 1), pf(n + 1, 0), div(n + 1, 0);

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		pf[i] = pf[i - 1] + a[i];
		if (a[i] <= k) ans = 1;
	}

	for (int i = 1; i <= n; ++i) {
		cin >> h[i];
	}

	for (int i = 1; i + 1 <= n; ++i) {
		if (h[i] % h[i + 1] == 0) {
			div[i] = 1;
		}
	}

	for (int i = 1; i <= n; ++i) {

		int l = i, r = i;
		while (div[r]) {
			r++;
		}

		if (l < r) {
			int lo = 0, hi = r - l + 1;

			while (lo <= hi) {
				int mid = (lo + hi) / 2;

				if (can(pf, l, r, mid, k)) {
					lo = mid + 1;
					ans = max(ans, mid);
				}
				else {
					hi = mid - 1;
				}
			}
			i = r;
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