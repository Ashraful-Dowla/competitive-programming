/*
https://atcoder.jp/contests/abc360/tasks/abc360_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin >> s;

	int ir, im;

	for (int i = 0; i < 3; ++i) {
		if (s[i] == 'R') {
			ir = i;
		}
		else if (s[i] == 'M') {
			im = i;
		}
	}

	if (ir < im) cout << "Yes" << endl;
	else cout << "No" << endl;
}