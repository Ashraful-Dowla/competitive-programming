//Author: Ashraful Dowla
/*
https://codeforces.com/contest/495/problem/C
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

	stack<pair<char, int>> stk;
	vector<pair<int, int>> hash;

	for (int i = 0; i < s.size(); ++i) {

		char ch = s[i];

		if (ch == '(') {
			stk.push({ch, i});
		}
		else {
			if (stk.empty() || stk.top().first != '(') {
				cout << -1 << endl;
				return ;
			}
			stk.pop();
			if (ch == '#') {
				hash.push_back({1, i});
			}
		}
	}

	while (!stk.empty() && hash.back().second > stk.top().second) {
		hash.back().first++;
		stk.pop();
	}

	if (stk.empty()) {
		for (auto p : hash) {
			cout << p.first << endl;
		}
	}
	else {
		cout << -1 << endl;
	}
}

int main() {
	Faster;

	solve();
}