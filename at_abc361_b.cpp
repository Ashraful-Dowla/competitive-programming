/*
https://atcoder.jp/contests/abc361/tasks/abc361_b
*/
#include <bits/stdc++.h>
using namespace std;

bool isValid(int x1, int x2, int y1, int y2) {

	if (x2 <= y1 or y2 <= x1) {
		return false;
	}

	return true;
}

int main() {

	int a, b, c, d, e, f;
	int g, h, i, j, k, l;

	cin >> a >> b >> c >> d >> e >> f;
	cin >> g >> h >> i >> j >> k >> l;


	if (isValid(a, d, g, j) and isValid(b, e, h, k) and isValid(c, f, i, l)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

}