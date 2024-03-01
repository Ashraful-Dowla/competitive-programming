//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1923/problem/C
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

	int n, q;
	cin >> n >> q;

	vll v(n + 1), pf(n + 1, 0), cnt1(n + 1, 0);

	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
	}

	for (int i = 1; i <= n; ++i) {
		pf[i] = pf[i - 1] + v[i];
		cnt1[i] = cnt1[i - 1] + (v[i] == 1);
	}

	while (q--) {
		int l, r;
		cin >> l >> r;

		if (l == r) {
			cout << "NO" << endl;
		}
		else {
			ll cnt = cnt1[r] - cnt1[l - 1];
			ll sum = pf[r] - pf[l - 1];

			if ((r - l + 1 + cnt) <= sum) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
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