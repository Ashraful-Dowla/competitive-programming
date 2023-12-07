//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1902/problem/B
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

	ll n, p, l, t;
	cin >> n >> p >> l >> t;

	ll lo = 0, hi = 1e9, res = 0;

	while (lo <= hi) {
		ll mid = (lo + hi) / 2;

		ll task = min(mid * 2 * t, t * ((n + 6) / 7));
		ll attend = mid * l;

		if (task + attend >= p) {
			res = mid;
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}

	cout << n - res << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}