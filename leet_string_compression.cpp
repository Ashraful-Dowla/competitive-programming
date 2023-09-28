/*
https://leetcode.com/problems/string-compression/
*/
#include <bits/stdc++.h>
using namespace std;

int compress(vector<char>& chars) {

	int n = chars.size();
	int cnt = 1, ans = 0, j = 0;
	for (int i = 1; i < n; ++i) {
		if (chars[i] == chars[i - 1]) {
			cnt++;
		}
		else {

			chars[j++] = chars[i - 1];

			if (cnt == 1) {
				ans++;
			}
			else {
				int len = log10(cnt) + 1;

				string num = to_string(cnt);

				for (int k = 0; k < num.size(); ++k) {
					chars[j++] = num[k];
				}

				ans += (len + 1);
				cnt = 1;
			}
		}
	}

	chars[j++] = chars[n - 1];

	if (cnt == 1) ans++;
	else {
		int len = log10(cnt) + 1;

		string num = to_string(cnt);

		for (int k = 0; k < num.size(); ++k) {
			chars[j++] = num[k];
		}

		ans += (len + 1);
	}

	return ans;
}

int main() {

	// vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
	//vector<char> chars = {'a'};
	vector<char> chars = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};

	int len = compress(chars);
	cout << len << endl;

	for (int i = 0; i < len; ++i) {
		cout << chars[i] << " ";
	}
}