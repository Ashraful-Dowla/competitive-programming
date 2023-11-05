/*
https://atcoder.jp/contests/abc324/tasks/abc324_b
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll n;
	cin >> n;

	while (n % 2 == 0) {
		n /= 2;
	}

	while (n % 3 == 0) {
		n /= 3;
	}

	cout << (n == 1 ? "Yes" : "No") << endl;
}