/*
https://atcoder.jp/contests/abc328/tasks/abc328_d
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin >> s;

	string ans;

	for (char ch : s) {
		ans += ch;
		int sz = ans.size();

		if (sz >= 3 && ans.substr(sz - 3) == "ABC") {
			ans.erase(ans.end() - 3, ans.end());
		}
	}
	cout << ans << endl;
}