//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1954/problem/B
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

	vi v(n);

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	int lst = -1, ans = n;

	for (int i = 1; i < n; ++i) {
		if (v[i] != v[0]) {
			ans = min(ans, i - lst - 1);
			lst = i;
		}
	}

	ans = min(ans, n - lst - 1);

	if (ans == n) {
		cout << -1 << endl;
	}
	else {
		cout << ans << endl;
	}
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}