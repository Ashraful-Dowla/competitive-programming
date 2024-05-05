#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> v(n + 2);

	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
	}

	int q;
	cin >> q;

	while (q--) {
		int t;
		cin >> t;

		if (t == 1) {
			int k, x;
			cin >> k >> x;
			v[k] = x;
		}
		else {
			int k;
			cin >> k;
			cout << v[k] << endl;
		}
	}
}