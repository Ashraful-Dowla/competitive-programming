#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

int binaryExp(int a, int b, int m) {
	int ans = 1;
	while (b) {
		if (b & 1) ans = (ans * 1LL * a) % m;
		a = (a * 1LL * a) % m;
		b >>= 1;
	}

	return ans;
}

int main() {
	int a;
	cin >> a;
	cout << binaryExp(a, M - 2, M) << endl; // a^-1 = (a^m-2)%m
}