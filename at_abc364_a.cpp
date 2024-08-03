/*
https://atcoder.jp/contests/abc364/tasks/abc364_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	vector<string> v(n);

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	int eat = 0;
	for (int i = 0; i < n; ++i) {
		if (i + 1 < n && v[i] == "sweet" && v[i + 1] == "sweet") {
			eat += 2;
			break;
		}
		eat++;
	}

	cout << (eat == n ? "Yes" : "No") << endl;
}