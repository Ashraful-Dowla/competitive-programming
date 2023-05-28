//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1833/problem/B
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
#define all(c) (c).begin(),(c).end()

//debug
#define vec_prnt(v) for(auto x: v) { cout<<x<<" "; } cout<<"\n"
#define prnt1(x) cout<<x<<endl
#define prnt2(x,y) cout<<x<<" "<<y<<endl

const int N = 1e5 + 10;
const int MOD = 1e9 + 7;

bool cmp(pii a, pii b) {
	return a.first < b.first;
}

void solve() {
	int n, k;
	cin >> n >> k;

	vector<pii> a;
	vi b(n);

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;

		a.pb({x, i});
	}

	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}

	sort(all(b));
	sort(a.begin(), a.end(), cmp);

	vi ans(n);
	for (int i = n - 1; i >= 0; --i) {
		ans[a[i].second] = b[i];
	}

	vec_prnt(ans);
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}