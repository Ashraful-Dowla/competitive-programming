/*
https://atcoder.jp/contests/abc339/tasks/abc339_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin >> s;

	reverse(s.begin(), s.end());

	int i = 0;
	string ans;
	while (i < s.size() &&  s[i] != '.') {
		ans.push_back(s[i]);
		i++;
	}

	reverse(ans.begin(), ans.end());
	cout << ans << endl;
}