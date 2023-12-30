/*
https://atcoder.jp/contests/abc301/tasks/abc301_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	string s;
	cin >> s;

	int wins[2] = {0}, last[2] = {0};

	for (int i = 0; i < n; ++i) {

		if (s[i] == 'T') {
			wins[0]++;
			last[0] = i;
		}
		else {
			wins[1]++;
			last[1] = i;
		}
	}

	if (wins[0] > wins[1]) {
		cout << "T" << endl;
	}
	else if (wins[0] < wins[1]) {
		cout << "A" << endl;
	}
	else if (last[0] < last[1]) {
		cout << "T" << endl;
	}
	else {
		cout << "A" << endl;
	}
}