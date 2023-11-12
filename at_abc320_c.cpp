/*
https://atcoder.jp/contests/abc320/tasks/abc320_c
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int m;
	cin >> m;

	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;

	s1 = s1 + s1 + s1;
	s2 = s2 + s2 + s2;
	s3 = s3 + s3 + s3;

	int ans = INT_MAX;

	for (int i = 0; i < s1.size(); ++i) {
		for (int j = 0; j < s2.size(); ++j) {
			for (int k = 0; k < s3.size(); ++k) {

				if (i != j && i != k && j != k
				        && s1[i] == s2[j] && s2[j] == s3[k]) {
					ans = min(ans, max({i, j, k}));
				}
			}
		}
	}

	cout << (ans == INT_MAX ? -1 : ans) << endl;

}