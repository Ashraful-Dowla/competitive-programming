//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1926/problem/B
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

	int a[n][n], dp[n][n], one = 0;

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < n; ++j) {
			a[i][j] = s[j] - '0';
			dp[i][j] = 0;
			if (a[i][j]) one++;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		dp[i][0] = a[i][0];
		dp[0][i] = a[0][i];
		ans = max({ans, dp[i][0], dp[0][i]});
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < n; ++j) {
			if (a[i][j] == 0) continue;
			dp[i][j] = min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]}) + 1;
			ans = max(ans, dp[i][j]);
		}
	}

	if (ans * ans == one) cout << "SQUARE" << endl;
	else cout << "TRIANGLE" << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}