//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1921/problem/D
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

	vector<ll> a(n);

	multiset<ll> ms;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < m; ++i) {
		ll b;
		cin >> b;
		ms.insert(b);
	}

	sort(a.begin(), a.end());

	int lo = 0, hi = n - 1;

	ll ans = 0;
	while (lo <= hi) {
		auto mx = (--ms.end());
		auto mn = ms.begin();

		if (abs(a[lo] - *mx) >= abs(a[hi] - *mn)) {
			ans += abs(a[lo] - *mx);
			ms.erase(mx);
			lo++;
		}
		else {
			ans += abs(a[hi] - *mn);
			ms.erase(mn);
			hi--;
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