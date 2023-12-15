/*
https://atcoder.jp/contests/abc307/tasks/abc307_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<char, int> pci;

int main() {
	int n;
	cin >> n;

	string s;
	cin >> s;

	stack<pci> stk;

	for (int i = 0; i < n; ++i) {

		while (!stk.empty() && stk.top().second > 0
		        && stk.top().first != '(' && s[i] == ')') {
			stk.pop();
		}

		if (!stk.empty() && stk.top().first == '(' && s[i] == ')') {
			stk.pop();
		}
		else if (stk.empty()) {
			stk.push({s[i], s[i] == '('});
		}
		else {
			int open = stk.top().second;
			stk.push({s[i], open + (s[i] == '(')});
		}
	}

	string ans;
	while (!stk.empty()) {
		ans.push_back(stk.top().first);
		stk.pop();
	}

	reverse(ans.begin(), ans.end());
	cout << ans << endl;
}