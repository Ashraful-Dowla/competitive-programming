/*
https://atcoder.jp/contests/abc297/tasks/abc297_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin >> s;

	vector<int> b, r;
	int k;

	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'B') {
			b.push_back(i);
		}
		else if (s[i] == 'R') {
			r.push_back(i);
		}
		else if (s[i] == 'K') {
			k = i;
		}
	}


	if (r[0] < k && k < r[1]) {
		if (b[0] % 2 != b[1] % 2) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	else {
		cout << "No" << endl;
	}
}