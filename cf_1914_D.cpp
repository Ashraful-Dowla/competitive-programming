//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1914/problem/D
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

int n;
vector<ll> a(N), b(N), c(N);
ll dp[N][2][2][2];

ll resolve(int i, bool aa, bool bb, bool cc) {


	if (i == n) {
		if (aa && bb && cc) return 0;
		return -1e16;
	}
	if (dp[i][aa][bb][cc] != -1) {
		return dp[i][aa][bb][cc];
	}

	ll ans = 0;
	if (!aa) {
		ans = max(ans, resolve(i + 1, true, bb, cc) + a[i]);
	}
	if (!bb) {
		ans = max(ans, resolve(i + 1, aa, true, cc) + b[i]);
	}
	if (!cc) {
		ans = max(ans, resolve(i + 1, aa, bb, true) + c[i]);
	}

	ans = max(ans, resolve(i + 1, aa, bb, cc));

	return dp[i][aa][bb][cc] = ans;
}

void solve() {

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}

	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= 1; ++j) {
			for (int k = 0; k <= 1; ++k) {
				for (int l = 0; l <= 1; ++l) {
					dp[i][j][k][l] = -1;
				}
			}
		}
	}

	cout << resolve(0, 0, 0, 0) << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}