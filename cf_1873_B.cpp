//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1873/problem/B
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

ll dp[12][2];

ll calc(vector<ll>& digits, int n, int i, int taken) {

	if (i == n) return 1;
	if (dp[i][taken] != -1) return dp[i][taken];

	ll res = calc(digits, n, i + 1, taken) * digits[i];
	if (!taken) {
		res = max(res, calc(digits, n, i + 1, true) * (digits[i] + 1));
	}

	return dp[i][taken] = res;
}

void solve() {
	int n;
	cin >> n;

	vector<ll> digits(n);

	for (int i = 0; i <= n; ++i) {
		dp[i][0] = dp[i][1] = -1;
	}

	for (int i = 0; i < n; ++i) {
		cin >> digits[i];
	}

	cout << calc(digits, n, 0, false) << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}