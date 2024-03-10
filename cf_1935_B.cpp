//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1935/problem/B
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

	set<int> s1, s2;
	vi v(n);

	s1.insert(n), s2.insert(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		s1.insert(i);
		s2.insert(i);
	}

	vi pf_mex(n);
	for (int i = 0; i < n; ++i) {
		auto it = s1.find(v[i]);
		if (it != s1.end()) {
			s1.erase(it);
		}
		pf_mex[i] = *s1.begin();
	}

	vi sf_mex(n);
	for (int i = n - 1; i >= 0; --i) {
		auto it = s2.find(v[i]);
		if (it != s2.end()) {
			s2.erase(it);
		}
		sf_mex[i] = *s2.begin();
	}

	for (int i = 0; i + 1 < n; ++i) {
		if (pf_mex[i] == sf_mex[i + 1]) {
			cout << 2 << endl;
			cout << 1 << " " << i + 1 << endl;
			cout << i + 2 << " " << n << endl;
			return ;
		}
	}

	cout << -1 << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}