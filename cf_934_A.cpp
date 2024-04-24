//Author: Ashraful Dowla
/*
https://codeforces.com/problemset/problem/934/A
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

	int n, m;
	cin >> n >> m;

	vector<ll>a(n), b(m);

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}

	ll ans = 1e18;
	for (int i = 0; i < n; ++i) {
		ll mx = -1e18;
		for (int j = 0; j < n; ++j) {
			if (j == i) continue;
			for (int k = 0; k < m; ++k) {
				mx = max(mx, a[j] * b[k]);
			}
		}

		ans = min(ans, mx);
	}

	cout << ans << endl;
}

int main() {
	Faster;

	solve();
}