//Author: Ashraful Dowla
/*
https://codeforces.com/problemset/problem/1833/D
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

	int arr[n + 2];
	int idx;

	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		if (arr[i] == n) {
			idx = i;
		}
	}

	if (n == 1) {
		prnt1(arr[1]);
		return ;
	}

	vi ans;
	if (idx > 1) {

		int r = idx - 1;
		for (int i = 1; i <= r; ++i ) {
			vi vec;

			for (int j = r + 1; j <= n; ++j) {
				vec.pb(arr[j]);
			}

			for (int l = r; l >= i; --l) {
				vec.pb(arr[l]);
			}

			for (int k = 1; k < i; ++k) {
				vec.pb(arr[k]);
			}

			if (vec.empty()) {
				ans = vec;
			}
			else {
				ans = max(ans, vec);
			}
		}

		if (idx == n) {
			vi ans2;
			ans2.pb(n);
			for (int i = 1; i < n; ++i) {
				ans2.pb(arr[i]);
			}
			ans = max(ans, ans2);
		}

	}
	else {
		for (int i = 1; i <= n; ++i) {
			if (arr[i] == n - 1) {
				idx = i;
				break;
			}
		}

		int r = idx - 1;
		for (int i = 1; i <= r; ++i ) {
			vi vec;

			for (int j = r + 1; j <= n; ++j) {
				vec.pb(arr[j]);
			}

			for (int l = r; l >= i; --l) {
				vec.pb(arr[l]);
			}

			for (int k = 1; k < i; ++k) {
				vec.pb(arr[k]);
			}

			if (vec.empty()) {
				ans = vec;
			}
			else {
				ans = max(ans, vec);
			}
		}

		if (idx == n) {
			vi ans2;
			ans2.pb(n - 1);
			for (int i = 1; i < n; ++i) {
				ans2.pb(arr[i]);
			}
			ans = max(ans, ans2);
		}

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