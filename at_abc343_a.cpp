/*
https://atcoder.jp/contests/abc343/tasks/abc343_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int a, b;
	cin >> a >> b;

	for (int i = 0; i <= 9; ++i) {
		if (i != a + b) {
			cout << i << endl;
			return 0;
		}
	}
}