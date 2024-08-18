/*
https://atcoder.jp/contests/abc367/tasks/abc367_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin >> s;

	while (s.size() > 0) {
		if (s.back() == '0') {
			s.pop_back();
		}
		else  {
			if (s.back() == '.') {
				s.pop_back();
			}
			break;
		}
	}

	cout << s << endl;
}