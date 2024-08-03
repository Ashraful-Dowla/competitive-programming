#include <bits/stdc++.h>
using namespace std;

int maximumGain(string s, int x, int y) {

	int ans = 0;
	char c1 = 'a', c2 = 'b';

	if (x < y) {
		swap(c1, c2);
	}

	string v;
	for (char ch : s) {
		if (ch == c2 && !v.empty() && v.back() == c1) {
			ans += max(x, y);
			v.pop_back();
		}
		else {
			v.push_back(ch);
		}
	}

	string p;
	for (char ch : v) {
		if (ch == c1 && !p.empty() && p.back() == c2) {
			ans += min(x, y);
			p.pop_back();
		}
		else {
			p.push_back(ch);
		}
	}

	return ans;
}

int main() {

	string s = "cdbcbbaaabab";
	int x = 4, y = 5;

	cout << maximumGain(s, x, y) << endl;
}