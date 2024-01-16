#include <bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin >> s;

	vector<pair<char, int>> v;

	for (char ch : s) {

		if (v.empty() || v.back().first != ch) {
			v.push_back({ch, 1});
		}
		else {
			v.back().second++;
		}
	}

	int len = 0;
	for (auto p : v) {
		len = max(len, p.second);
	}

	cout << len << endl;
}