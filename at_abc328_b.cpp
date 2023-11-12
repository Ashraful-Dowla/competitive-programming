/*
https://atcoder.jp/contests/abc328/tasks/abc328_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	int days[n + 1];

	for (int i = 1; i <= n; ++i) {
		cin >> days[i];
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) {

		string s = to_string(i);

		set<char>ss;

		for (char ch : s) {
			ss.insert(ch);
		}

		if (ss.size() != 1)
			continue;

		for (int j = 1; j <= days[i]; ++j) {

			string r = to_string(j);

			set<char> tt = ss;
			for (char ch : r) {
				tt.insert(ch);
			}

			if (tt.size() == 1) {
				ans++;
			}

		}
	}

	cout << ans << endl;
}