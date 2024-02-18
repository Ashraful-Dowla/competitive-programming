//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1931/problem/C
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

	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	vector<pii> vv;

	for (int i = 0; i < n; ++i) {
		if (vv.empty() || vv.back().first != v[i]) {
			vv.push_back({v[i], 1});
		}
		else {
			vv.back().second++;
		}
	}

	if (vv.size() == 1) cout << 0 << endl;
	else {
		int sz = vv.size();
		if (vv[0].first == vv[sz - 1].first) {
			cout << n - (vv[0].second + vv[sz - 1].second) << endl;
		}
		else {
			cout << min(n - vv[0].second, n - vv[sz - 1].second) << endl;
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