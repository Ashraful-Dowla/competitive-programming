/*
https://atcoder.jp/contests/abc283/tasks/abc283_d
*/
#include <bits/stdc++.h>
using namespace std;

int main() {


	string s;
	cin >> s;

	multiset<char> ms;
	stack<char> stk;

	for (char ch : s) {

		if (ch == '(') {
			stk.push(ch);
		}
		else if (ch == ')') {
			while (stk.top() >= 'a' && stk.top() <= 'z') {
				ms.erase(ms.find(stk.top()));
				stk.pop();
			}
			stk.pop();
		}
		else {
			stk.push(ch);
			if (ms.count(ch) > 0) {
				cout << "No" << endl;
				return 0;
			}
			ms.insert(ch);
		}
	}

	cout << "Yes" << endl;
}