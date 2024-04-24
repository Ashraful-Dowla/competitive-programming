//Author: Ashraful Dowla
/*
https://codeforces.com/problemset/problem/1945/D
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

	ll a[n + 1], b[n + 1], pb[n + 1];

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		pb[i] = pb[i - 1] + b[i];
	}

	int pos = n + 1, j = n;

	ll res = 0;
	while (j > m) {
		if (a[j] < b[j]) {
			res += a[j] + pb[pos - 1] - pb[j];
			pos = j;
		}
		j--;
	}

	ll ans = 1e18;
	for (int i = 1; i <= m; ++i) {
		ans = min(ans, res + a[i] + pb[pos - 1] - pb[i]);
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