/*
https://atcoder.jp/contests/abc291/tasks/abc291_c
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
map<pii, bool> mp;

int main() {

	int n;
	cin >> n;

	string s;
	cin >> s;

	int x = 0, y = 0;
	for (char ch : s) {

		mp[ {x, y}] = true;

		if (ch == 'L') {
			x++;
		}
		else if (ch == 'R') {
			x--;
		}
		else if (ch == 'U') {
			y++;
		}
		else {
			y--;
		}

		if (mp[ {x, y}]) {
			cout << "Yes" << endl;
			return 0;
		}
	}

	cout << "No" << endl;

}