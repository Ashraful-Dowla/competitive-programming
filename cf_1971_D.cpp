//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1971/problem/D
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve() {

	string s;
	cin >> s;

	vector<pair<char, int>> v;

	for (char ch : s) {

		if (v.empty() || v.back().first != ch) {
			v.push_back({ch, 1});
		}
		else {
			v.back().second++;
		}
	}

	if (v.size() == 1) {
		cout << 1 << endl;
		return ;
	}

	int idx = -1;
	for (int i = 0; i + 1 < v.size(); ++i) {
		if (v[i].first == '0' && v[i + 1].first == '1') {
			int sz = v[i].second + v[i + 1].second;
			idx = i;
		}
	}

	if (idx == -1) {
		cout << v.size() << endl;
	}
	else {
		cout << v.size() - 1 << endl;
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