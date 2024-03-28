/*
https://atcoder.jp/contests/abc346/tasks/abc346_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int w, b;
	cin >> w >> b;

	string s = "wbwbwwbwbwbw";

	for (int i = 0; i < s.size(); ++i) {
		int ww = 0, bb = 0;
		for (int j = 0; j < w + b; ++j) {
			if (s[(i + j) % s.size()] == 'w') ++ww;
			else ++bb;
		}

		if (ww == w && bb == b) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
}