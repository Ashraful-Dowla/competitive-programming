/*
https://atcoder.jp/contests/abc285/tasks/abc285_c
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	string s;
	cin >> s;

	ll res = 0;

	for (char ch : s) {
		res = res * 26 + (ch - 'A' + 1);
	}

	cout << res << endl;

}