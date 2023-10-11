//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1886/problem/C
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
	string s;
	cin >> s;
	ll k;
	cin >> k;

	int n = s.size();
	s = "_" + s;

	stack<int> stk;
	vector<int> vec;

	for (int i = 1; i <= n; ++i) {

		while (!stk.empty() && s[stk.top()] > s[i]) {
			vec.push_back(stk.top());
			stk.pop();
		}

		stk.push(i);
	}

	while (!stk.empty()) {
		vec.push_back(stk.top());
		stk.pop();
	}

	ll pos = 1, sz;
	for (int i = 0, p = n; i < vec.size(); ++i, --p) {
		if (pos <= k && k < pos + p) {
			sz = i;
			k -= (pos - 1);
			break;
		}
		pos += p;
		s[vec[i]] = '_';
	}

	for (int i = 1; i <= n; ++i) {
		if (s[i] != '_') {
			k--;
			if (k == 0) {
				cout << s[i];
				break;
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