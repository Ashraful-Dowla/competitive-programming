/*
https://atcoder.jp/contests/abc301/tasks/abc301_c
*/
#include <bits/stdc++.h>
using namespace std;

bool check(char ch) {
	string s = "atcoder";
	for (char c : s) {
		if (c == ch) {
			return true;
		}
	}

	return false;
}

int main() {

	string s, t;
	cin >> s;
	cin >> t;

	int cs = 0;
	multiset<char> ms, mt;

	for (char ch : s) {
		if (ch == '@') {
			cs++;
		}
		else {
			ms.insert(ch);
		}
	}

	for (char ch : t) {
		mt.insert(ch);
	}

	while (ms.size() > 0 && mt.size() > 0) {

		char st = *ms.begin();

		if (mt.find(st) != mt.end()) {
			mt.erase(mt.find(st));
		}
		else if (mt.find('@') != mt.end() && check(st)) {
			mt.erase(mt.find('@'));
		}
		else {
			cout << "No" << endl;
			return 0;
		}
		ms.erase(ms.find(st));
	}

	for (char ch : mt) {
		if ((check(ch) || ch == '@') && cs > 0) {
			cs--;
		}
	}

	if (ms.size() == 0 && cs == 0) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

}