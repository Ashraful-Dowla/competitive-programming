/*
https://atcoder.jp/contests/abc289/tasks/abc289_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin >> s;

	for (char ch : s) {
		cout << (ch != '1');
	}
	cout << endl;
}