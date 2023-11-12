/*
https://atcoder.jp/contests/abc320/tasks/abc320_a
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll pw(int a, int b) {

	ll res = 1;
	for (int i = 0; i < b; ++i) {
		res *= a;
	}

	return res;
}

int main() {

	int a, b;
	cin >> a >> b;
	cout << pw(a, b) + pw(b, a) << endl;
}