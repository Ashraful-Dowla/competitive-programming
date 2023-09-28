//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1879/problem/A
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

	vector<pii> vec;

	for (int i = 0; i < n; ++i) {
		int s, e;
		cin >> s >> e;
		vec.push_back({s, e});
	}

	int mx_s = vec[0].first, mx_e = vec[0].second;

	int e = 0;
	for (int i = 1; i < n; ++i) {
		if (mx_s <= vec[i].first) {
			e = max(e, vec[i].second);
		}
	}

	if (e >= mx_e) cout << -1 << endl;
	else cout << mx_s << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}