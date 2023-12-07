//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1902/problem/C
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

	vector<ll> v(n);

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	if (n == 1) {
		cout << 1 << endl;
		return ;
	}

	sort(v.begin(), v.end());

	ll gcd = 0;
	for (int i = 1; i < n; ++i) {
		gcd = __gcd(gcd, v[i] - v[i - 1]);
	}

	ll nw = 3e9;

	for (int i = n - 1; i >= 1; --i) {
		if (v[i] - v[i - 1] > gcd) {
			nw = v[i] - gcd;
			break;
		}
	}

	nw = min(nw, v.back() + gcd);
	ll mx = max(nw, v.back());

	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += (mx - v[i]) / gcd;
	}
	ans += (mx - nw) / gcd;

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