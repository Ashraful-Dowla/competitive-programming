//Author: Ashraful Dowla
/*
https://codeforces.com/group/7Dn3ObOpau/contest/494787/problem/C
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

	int n, k;
	cin >> n >> k;

	ll start;
	cin >> start;

	vector<ll> point(n + 1, 0), dis(n + 2), dp(n + 1, 1e15), pf(n + 1, 0), delta(n + 1, 0);

	for (int i = 1; i <= n; ++i) {
		cin >> point[i];
		dis[i] = abs(start - point[i]);
	}

	for (int i = 2; i <= n; ++i) {
		pf[i] = pf[i - 1] + abs(point[i] - point[i - 1]);
	}

	for (int i = 1; i <= n; ++i) {
		delta[i] = dis[i] + dis[i + 1] - pf[i + 1];
	}

	dp[1] = dis[1];

	multiset<ll> ms;
	ms.insert(dp[1] + delta[1]);

	for (int i = 2; i <= n; ++i) {

		dp[i] = *ms.begin() + pf[i];

		if (k >= i) {
			dp[i] = min(dp[i], dp[i - 1] + abs(point[i] - point[i - 1]));
		}

		ms.insert(dp[i] + delta[i]);

		if (ms.size() > k) {
			ms.erase(ms.find(dp[i - k] + delta[i - k]));
		}
	}

	for (int i = 1; i <= n; ++i) {
		cout << dp[i] + dis[i] << " ";
	}
	cout << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}