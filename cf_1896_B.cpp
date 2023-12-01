//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1896/problem/B
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

	string s;
	cin >> s;

	vector<pair<char, int>> v;
	for (int i = 0; i < n; ++i) {
		if (v.empty() || v.back().first != s[i]) {
			v.push_back({s[i], 1});
		}
		else {
			v.back().second++;
		}
	}

	int ans = 0, st = -1;

	if (v[0].first == 'A') st = 1;
	else st = 2;

	for (int i = st; i < v.size(); i += 2) {

		if (v[i - 1].first == 'A' && v[i].first == 'B') {
			ans += v[i - 1].second + v[i].second - 1;
		}

		if (i + 1 < v.size()) {
			v[i + 1].second++;
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