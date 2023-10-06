//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1875/problem/D
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

ll dp[5005][5005];

ll calc(vector<pii>& vec, int i, int mex) {

	if (i < 0) return 0;
	if (i == 0) return (vec[i].second - 1) * mex;
	if (dp[i][mex] != -1) return dp[i][mex];

	ll ans = 1e15;

	ans = min(ans, calc(vec, i - 1, vec[i].first)
	          + (vec[i].second - 1) * 1LL * mex + vec[i].first);

	ans = min(ans, calc(vec, i - 1, mex));

	return dp[i][mex] = ans;

}

void dp_clr(int n, int mex) {
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= mex; ++j) {
			dp[i][j] = -1;
		}
	}
}


void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	unordered_map<int, bool> taken;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		taken[a[i]] = true;
	}

	sort(all(a));
	vector<pii> vec;

	for (int i = 0; i < n; ++i) {
		if (vec.empty() || vec.back().first != a[i]) {
			vec.push_back({a[i], 1});
		}
		else {
			vec.back().second++;
		}
	}

	int mex = 0;
	for (int i = 0; i <= 5000; ++i) {
		if (!taken[i]) {
			mex = i;
			break;
		}
	}

	dp_clr(n, mex);
	cout << calc(vec, mex - 1, mex) << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}