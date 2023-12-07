/*
https://atcoder.jp/contests/abc331/tasks/abc331_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int M, D;
	cin >> M >> D;

	int y, m, d;
	cin >> y >> m >> d;

	if (d + 1 <= D) {
		cout << y << " " << m << " " << d + 1 << endl;
	}
	else {
		if (m + 1 <= M) {
			cout << y << " " << m + 1 << " " << 1 << endl;
		}
		else {
			cout << y + 1 << " " << 1 << " " << 1 << endl;
		}
	}
}