/*
https://atcoder.jp/contests/abc308/tasks/abc308_e
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int get_mex(int a, int b, int c) {

	for (int i = 0; i < 3; ++i) {
		if (a != i && b != i && c != i) {
			return i;
		}
	}

	return 3;
}

int main() {

	int n;
	cin >> n;
	vector<int> mex(n);

	for (int i = 0; i < n; ++i) {
		cin >> mex[i];
	}

	string s;
	cin >> s;

	ll fqr[4] = {0}, fql[4] = {0};

	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'X') {
			fqr[mex[i]]++;
		}
	}

	ll ans = 0;
	for (int i = 0; i < n; ++i) {

		if (s[i] == 'X') {
			fqr[mex[i]]--;
		}
		else if (s[i] == 'E') {
			for (int l = 0; l < 3; ++l) {
				for (int r = 0; r < 3; ++r) {
					int res = get_mex(l, mex[i], r);
					ans += res * fql[l] * fqr[r];
				}
			}
		}
		else if (s[i] == 'M') {
			fql[mex[i]]++;
		}
	}

	cout << ans << endl;

}