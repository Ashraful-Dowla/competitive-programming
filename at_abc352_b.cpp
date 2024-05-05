/*
https://atcoder.jp/contests/abc352/tasks/abc352_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin >> s;
	string t;
	cin >> t;

	for (int i = 0, j = 0; i < s.size() && j < t.size(); ++j) {
		if (s[i] == t[j]) {
			i++;
			cout << j + 1 << " ";
		}
	}
	cout << endl;
}