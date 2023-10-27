/*
https://www.hackerearth.com/problem/algorithm/help-joe/
*/

#include <bits/stdc++.h>
using namespace std;

int hsh[26];

int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		hsh[s[i] - 'a']++;
	}
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		int oddCnt = 0;
		int cnt = 0;
		bool chk[26];
		memset(chk, false, sizeof(chk));

		for (int i = 0; i < n; i++) {
			char ch;
			cin >> ch;
			if (!chk[ch - 'a']) {
				if (hsh[ch - 'a'] % 2 != 0) {
					oddCnt++;
				}
				cnt += (hsh[ch - 'a']);
				chk[ch - 'a'] = true;
			}

		}

		if (oddCnt > 1) cnt -= (oddCnt - 1);
		cout << cnt << endl;
	}
}