/*
https://www.hackerearth.com/problem/algorithm/doraemon-and-mii-chan/
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int hsh[N];

int main() {
	int m, n;
	cin >> m >> n;
	while (m--) {
		int l, k;
		cin >> l >> k;
		hsh[k]++;
	}
	int d;
	bool check = true;
	for (int i = 0; i < n; i++) {
		cin >> d;
		if (hsh[d] == 0) check = false;
	}

	cout << (check ? "YES" : "NO") << endl;
}