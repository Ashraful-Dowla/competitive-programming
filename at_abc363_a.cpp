/*
https://atcoder.jp/contests/abc363/tasks/abc363_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int r;
	cin >> r;

	if (r < 100) {
		cout << 100 - r << endl;
	}
	else if (r < 200) {
		cout << 200 - r << endl;
	}
	else {
		cout << 300 - r << endl;
	}
}