/*
https://cses.fi/problemset/task/1755/
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin >> s;

	int ch[26] = {0};

	for (char c : s) {
		ch[c - 'A']++;
	}

	vector<char> ve, vo;
	for (int i = 0; i < 26; ++i) {
		if (ch[i] == 0) continue;
		if (ch[i] % 2 == 0) {
			ve.push_back(i + 'A');
		}
		else {
			vo.push_back(i + 'A');
		}
	}

	if (vo.size() > 1) {
		cout << "NO SOLUTION" << endl;
	}
	else {

		deque<char> ans;
		if (vo.size()) {
			for (int i = 0; i < ch[vo[0] - 'A']; ++i) {
				ans.push_back(vo[0]);
			}
		}

		for (char c : ve) {
			for (int i = 0; i < ch[c - 'A']; i += 2) {
				ans.push_back(c);
				ans.push_front(c);
			}
		}

		while (!ans.empty()) {
			cout << ans.front();
			ans.pop_front();
		}
	}
}