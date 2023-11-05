/*
https://atcoder.jp/contests/abc322/tasks/abc322_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;
	string s;
	cin >> s;

	int idx = -1;
	for (int i = 0; i + 2 < s.size(); ++i) {

		if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C') {
			idx = i + 1;
			break;
		}
	}

	cout << idx << endl;

}