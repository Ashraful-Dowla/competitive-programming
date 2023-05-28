//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1832/problem/B
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

void solve() {
	int n, k;
	cin >> n >> k;

	ll arr[n + 2];
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}

	sort(arr + 1, arr + n + 1);

	ll pf[n + 2];
	pf[0] = 0;
	for (int i = 1; i <= n; ++i) {
		pf[i] = pf[i - 1] + arr[i];
	}

	ll ans = 0;
	for (int i = 0; i <= k; ++i) {
		// ll res = pf[n] - (pf[n] - pf[n - k + i] + pf[2 * i]);
		ll res = pf[n - k + i] - pf[2 * i];
		ans = max(ans, res);
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