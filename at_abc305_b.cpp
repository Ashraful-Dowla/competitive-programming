/*
https://atcoder.jp/contests/abc305/tasks/abc305_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	char p, q;
	cin >> p >> q;

	if (p > q) {
		swap(p, q);
	}

	vector<int> pf = {0, 3, 4, 8, 9, 14, 23};

	cout << pf[q - 'A'] - pf[p - 'A'] << endl;
}