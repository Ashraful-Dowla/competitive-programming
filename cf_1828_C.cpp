//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1828/problem/C
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
const ll MOD = 1e9 + 7;

void solve() {
	int n;
	cin >> n;

	vll a(n), b(n);

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}

	sort(all(a));
	sort(all(b));

	for (int i = 0; i < n; ++i) {
		if (a[i] > b[i]) continue;
		prnt1(0);
		return ;
	}

	ll ans = 1;

	for (int i = 0; i < n; ++i) {
		int lo = i, hi = n - 1;

		int idx;
		while (lo <= hi) {
			int mid = (hi + lo) / 2;

			if (a[i] > b[mid]) {
				idx = mid;
				lo = mid + 1;
			}
			else hi = mid - 1;
		}

		ans *= (idx - i + 1);
		ans %= MOD;
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