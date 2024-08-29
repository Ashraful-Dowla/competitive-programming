//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1997/problem/A
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int resolve(string s) {

	string p;
	int res = 0;
	for (char ch : s) {
		if (p.empty() || p.back() != ch) {
			res += 2;
		}
		else {
			res++;
		}
		p.push_back(ch);
	}

	return res;
}

void solve() {

	string s;
	cin >> s;

	int mx = 0;
	string ans;
	for (char ch = 'a'; ch <= 'z'; ++ch) {
		for (int i = 0; i < s.size(); ++i) {
			string p = s.substr(0, i) + ch + s.substr(i);
			int res = resolve(p);
			if (mx < res) {
				mx = res;
				ans = p;
			}
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