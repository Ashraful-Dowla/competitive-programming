/*
https://atcoder.jp/contests/abc375/tasks/abc375_b
*/
#include <bits/stdc++.h>
using namespace std;

double dis(double a, double b, double c, double d) {
	return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}

int main() {

	int n;
	cin >> n;

	double x[n], y[n];
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}

	double lx = 0, ly = 0, ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += dis(lx, ly, x[i], y[i]);
		lx = x[i], ly = y[i];
	}

	ans += dis(lx, ly, 0, 0);

	cout << fixed << setprecision(10) << ans << endl;
}