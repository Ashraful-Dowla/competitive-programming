/*
https://atcoder.jp/contests/abc304/tasks/abc304_b
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	ll n;
	cin >> n;

	if (n < 1e3) {
		cout << n << endl;
	}
	else if (n < 1e4) {
		cout << (n / 10) * 10 << endl; //ones
	}
	else if (n < 1e5) {
		cout << (n / 100) * 100 << endl; //tens
	}
	else if (n < 1e6) {
		cout << (n / 1000) * 1000 << endl; //hundred
	}
	else if (n < 1e7) {
		cout << (n / 10000) * 10000 << endl; //thousand
	}
	else if (n < 1e8) {
		cout << (n / 100000) * 100000 << endl; //ten thousand
	}
	else {
		cout << (n / 1000000) * 1000000 << endl;
	}

}