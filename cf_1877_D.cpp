//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1877/problem/D
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

	vector<ll> a(n + 1);

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; i * j <= n; ++j) {
			a[i] = max(a[i], a[i * j]);
		}
	}

	ll cnt = 1, ans = 0, MOD = 998244353;

	sort(a.begin() + 1, a.begin() + n + 1);

	for (int i = 1; i <= n; ++i) {
		ans = (ans + cnt * a[i]) % MOD;
		cnt = (cnt * 2) % MOD;
	}

	cout << ans << endl;
}

int main() {
	Faster;

	solve();
}