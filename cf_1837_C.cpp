//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1837/problem/C
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

	stack<int> stk;

	char last = '0';
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '?') {
			stk.push(i);
		}
		else {
			while (!stk.empty()) {
				int idx = stk.top();
				stk.pop();
				s[idx] = s[i];
			}
			last = s[i];
		}
	}

	while (!stk.empty()) {
		int idx = stk.top();
		stk.pop();
		s[idx] = last;
	}

	prnt1(s);
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}