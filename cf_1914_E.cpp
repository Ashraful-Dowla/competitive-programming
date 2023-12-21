//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1914/problem/E2
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

bool cmp(pair<ll, int> a, pair<ll, int> b) {
	return a.first > b.first;
}


void solve() {

	int n;
	cin >> n;

	ll a[n], b[n];

	vector<pair<ll, int>> v;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		v.push_back({a[i] + b[i], i});
	}

	ll ans = 0;

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; ++i) {

		if (i % 2 == 0) {
			a[v[i].second] -= 1;
			b[v[i].second] = 0;
		}
		else {
			b[v[i].second] -= 1;
			a[v[i].second] = 0;
		}
	}

	for (int i = 0; i < n; ++i) {
		ans += (a[i] - b[i]);
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