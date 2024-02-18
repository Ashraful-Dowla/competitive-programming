/*
https://atcoder.jp/contests/abc291/tasks/abc291_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin >> s;

	for (int i = 0; i < s.size(); ++i) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			cout << i + 1 << endl;
			return 0;
		}
	}
}