/*
https://atcoder.jp/contests/abc292/tasks/abc292_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin >> s;

	for (char ch : s) {
		cout << char(toupper(ch));
	}
}