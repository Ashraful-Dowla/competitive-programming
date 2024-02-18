/*
https://atcoder.jp/contests/abc340/tasks/abc340_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int f, l, d;
	cin >> f >> l >> d;


	for (int i = f; i <= l; i += d) {
		cout << i << " ";
	}
	cout << endl;
}