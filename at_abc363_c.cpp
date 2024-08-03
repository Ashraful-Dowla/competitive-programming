/*
https://atcoder.jp/contests/abc363/tasks/abc363_c
*/
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {

	int lo = 0, hi = s.size() - 1;

	while (lo < hi) {
		if (s[lo] != s[hi]) {
			return false;
		}
		lo++, hi--;
	}

	return true;
}

int main() {

	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	int ans = 0;
	sort(s.begin(), s.end());

	do {
		bool ok = true;
		for (int i = 0; i <= n - k; ++i) {
			if (isPalindrome(s.substr(i, k))) {
				ok = false;
				break;
			}
		}
		ans += ok;
	} while (next_permutation(s.begin(), s.end()));

	cout << ans << endl;
}