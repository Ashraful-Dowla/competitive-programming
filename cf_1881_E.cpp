//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1881/problem/E
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

const int N = 2e5 + 10;
const int MOD = 1e9 + 7;

int dp[N];

int resolve(vector<int>& a, int idx) {

	int n = a.size();
	if (idx == n) return 0;
	if (idx > n) return 1e7;
	if (dp[idx] != -1) return dp[idx];

	return dp[idx] = min(resolve(a, idx + a[idx] + 1), resolve(a, idx + 1) + 1);
}

void solve() {
	int n;
	cin >> n;

	vector<int> a(n);

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		dp[i] = -1;
	}

	cout << resolve(a, 0) << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}