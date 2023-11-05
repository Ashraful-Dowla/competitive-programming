//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1895/problem/B
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

	vector<ll> vec(2 * n);

	for (int i = 0; i < 2 * n; ++i) {
		cin >> vec[i];
	}

	sort(vec.rbegin(), vec.rend());

	vector<pll> coordinates;
	vector<ll> x, y;

	for (int i = 0; i < n; ++i) {
		x.push_back(vec[i]);
	}

	for (int i = n; i < 2 * n; ++i) {
		y.push_back(vec[i]);
	}

	ll ans = 0;

	coordinates.push_back({x[0], y[0]});
	for (int i = 1; i < n; ++i) {

		ll d = abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]);
		ans += d;

		coordinates.push_back({x[i], y[i]});
	}

	cout << ans << endl;

	for (auto p : coordinates) {
		cout << p.first << " " << p.second << endl;
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