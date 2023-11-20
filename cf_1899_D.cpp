//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1899/problem/D
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

	map<int, int> mp;
	set<int> s;

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;

		mp[x]++;

		s.insert(x);
	}

	ll ans = 0;
	for (int x : s) {

		ll res = mp[x] * 1LL * (mp[x] - 1);
		res /= 2;
		ans += res;

		if (x == 1) {
			ans += (mp[1] * 1LL * mp[2]);
		}
	}

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