/*
https://atcoder.jp/contests/abc299/tasks/abc299_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	string s;
	cin >> s;

	int st = -1, nd = -1, star = -1;

	for (int i = 0; i < n; ++i) {
		if (s[i] == '|') {
			if (st == -1) {
				st = i;
			}
			else if (nd == -1) {
				nd = i;
			}
		}
		else if (s[i] == '*') {
			star = i;
		}
	}


	if (st < star && star < nd) {
		cout << "in" << endl;
	}
	else {
		cout << "out" << endl;
	}
}