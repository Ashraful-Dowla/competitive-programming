//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1873/problem/E
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
const int MOD = 2e9 + 7;

void solve() {
	int n, x;
	cin >> n >> x;

	vector<ll> heights(n);

	for (int i = 0; i < n; ++i) {
		cin >> heights[i];
	}

	ll lo = 0, hi = MOD;

	ll ans = 0;
	while (lo <= hi) {

		ll mid = (lo + hi) / 2;

		ll volume = 0;

		for (int i = 0; i < n; ++i) {
			volume += max(mid - heights[i], 0LL);
		}

		if (volume <= x) {
			lo = mid + 1;
			ans = max(ans, mid);
		}
		else {
			hi = mid - 1;
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