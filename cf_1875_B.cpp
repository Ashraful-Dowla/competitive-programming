//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1875/problem/B
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
	int n, m, k;
	cin >> n >> m >> k;

	vector<ll> a(n), b(m);

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}

	sort(all(a));
	sort(all(b));

	if (a[0] < b[m - 1]) {
		swap(a[0], b[m - 1]);
	}

	if (k % 2 == 0) {
		sort(all(a));
		sort(all(b));

		if (b[0] < a[n - 1]) {
			swap(b[0], a[n - 1]);
		}
	}

	ll ans = accumulate(all(a), 0LL);
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