//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1927/problem/D
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

	int a[n + 1];
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	vector<int> p(n + 1, -1);

	for (int i = 2; i <= n; ++i) {
		if (a[i] != a[i - 1]) {
			p[i] = i - 1;
		}
		else {
			p[i] = p[i - 1];
		}
	}

	int q;
	cin >> q;

	while (q--) {
		int l, r;
		cin >> l >> r;

		if (l <= p[r]) {
			cout << p[r] << " " << r << endl;
		}
		else {
			cout << -1 << " " << -1 << endl;
		}
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