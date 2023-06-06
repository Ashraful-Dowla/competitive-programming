//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1831/problem/B
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

	vector<pii> a, b;

	vi a_mx(2 * n + 2, 0), b_mx(2 * n + 2, 0);
	set<int> s;

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (a.empty() || a.back().first != x) {
			a.pb({x, 1});
			s.insert(x);
		}
		else {
			a.back().second++;
		}

		a_mx[x] = max(a_mx[x], a.back().second);
	}

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (b.empty() || b.back().first != x) {
			b.pb({x, 1});
			s.insert(x);
		}
		else {
			b.back().second++;
		}

		b_mx[x] = max(b_mx[x], b.back().second);
	}

	int ans = 0;
	for (int x : s) {
		ans = max(ans, a_mx[x] + b_mx[x]);
	}

	prnt1(ans);
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}