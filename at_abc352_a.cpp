/*
https://atcoder.jp/contests/abc352/tasks/abc352_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, x, y, z;

	cin >> n >> x >> y >> z;

	if (x > y) {
		swap(x, y);
	}

	if (z >= x && z <= y) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}