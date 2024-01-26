#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	int st = 0, sa = 0;

	for (int i = 0; i < n; ++i) {
		int t, a;
		cin >> t >> a;

		st += t;
		sa += a;
	}

	if (st == sa) cout << "Draw" << endl;
	else if (st > sa) cout << "Takahashi" << endl;
	else cout << "Aoki" << endl;
}