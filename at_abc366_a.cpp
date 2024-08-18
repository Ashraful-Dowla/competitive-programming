/*
https://atcoder.jp/contests/abc366/tasks/abc366_a
*/ 
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, t, a;
	cin >> n >> t >> a;

	int d = (n + 1) / 2;

	if (t >= d || a >= d) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}