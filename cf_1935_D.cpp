//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1935/problem/D
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
	ll c;
	cin >> n >> c;

	vll v(n);

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	ll ans = ((c + 1) * (c + 2)) / 2;

	ll ev = 0, od = 0;
	for (int i = 0; i < n; ++i) {
		ans -= (v[i] / 2 + 1);
		ans -= (c - v[i] + 1);
		if (v[i] % 2 == 0) {
			ev++;
		}
		else {
			od++;
		}
	}

	ans += (ev * (ev + 1)) / 2;
	ans += (od * (od + 1)) / 2;
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