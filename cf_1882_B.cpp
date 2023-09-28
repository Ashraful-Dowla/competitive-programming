//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1882/problem/B
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


	vector<ll> vec(n, 0LL);
	ll un = 0;

	vector<int> cnt(55, 0LL);
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		for (int j = 0; j < k; ++j) {
			int x;
			cin >> x;
			vec[i] |= (1LL << x);
			cnt[x]++;
		}
		un |= vec[i];
	}

	int ans = 0;
	for (int s = 1; s <= 50; ++s) {
		set<int> st;
		for (int i = 0; i < n; ++i) {
			if ((vec[i] >> s) & 1) continue;

			for (int j = 1; j <= 50; ++j) {
				if ((vec[i] >> j) & 1) {
					st.insert(j);
				}
			}
		}

		int len = __builtin_popcountll(un);
		int sz = st.size();
		if (len != sz) {
			ans = max(ans, sz);
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