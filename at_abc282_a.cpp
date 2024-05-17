/*
https://atcoder.jp/contests/abc282/tasks/abc282_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int k;
	cin >> k;

	for (char ch = 'A'; ch <= 'Z' && k > 0; ch++, k--) {
		cout << ch;
	}
	cout << endl;
}