/*
https://atcoder.jp/contests/abc337/tasks/abc337_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin >> s;

	vector<char> v;

	for (int i = 0; i < s.size(); ++i) {
		if (v.empty() || v.back() != s[i]) {
			v.push_back(s[i]);
		}
	}

	if (v.size() == 1) cout << "Yes" << endl;
	else if (v.size() == 2) {

		string r;
		for (char ch : v) {
			r.push_back(ch);
		}

		if (r == "AB" || r == "AC" || r == "BC") cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	else if (v.size() == 3) {
		if (v[0] == 'A' && v[1] == 'B' && v[2] == 'C') cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	else {
		cout << "No" << endl;
	}
}