//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1917/problem/C
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

	int n, k, d;
	cin >> n >> k >> d;

	ll a[n + 1], v[k + 1];

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	for (int i = 1; i <= k; ++i) {
		cin >> v[i];
	}

	ll ans = 0, cnt = 0;
	for (int i = 1; i <= min(2 * n, d); ++i) {
		cnt = 0;
		for (int j = 1; j <= n; ++j) {
			if (a[j] == j) {
				cnt++;
			}
		}

		ans = max(ans, cnt + (d - i) / 2);

		for (int j = 1; j <= v[1 + (i - 1) % k]; ++j) {
			a[j]++;
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