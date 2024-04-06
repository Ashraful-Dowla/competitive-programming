#include <bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin >> s;

	map<string, bool> fq;
	for (int i = 0; i < s.size(); ++i) {
		string p;
		for (int j = i; j < s.size(); ++j) {
			p.push_back(s[j]);
			fq[p] = true;
		}
	}

	cout << fq.size() << endl;
}