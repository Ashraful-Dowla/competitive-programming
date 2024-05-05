/*
https://atcoder.jp/contests/abc351/tasks/abc351_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {


	int t = 0;
	for (int i = 0; i < 9; ++i) {
		int x;
		cin >> x;
		t += x;
	}

	int a = 0;
	for (int i = 0; i < 8; ++i) {
		int x;
		cin >> x;
		a += x;
	}

	cout << t - a + 1 << endl;
}