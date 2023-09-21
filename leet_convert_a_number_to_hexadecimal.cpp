/*
https://leetcode.com/problems/convert-a-number-to-hexadecimal/
*/
#include <bits/stdc++.h>
using namespace std;

unordered_map<int, char> hex_list = {
	{10, 'a'},
	{11, 'b'},
	{12, 'c'},
	{13, 'd'},
	{14, 'e'},
	{15, 'f'}
};

vector<int> num_to_binary(int n) {

	vector<int> bin;
	for (int i = 31; i >= 0; --i) {
		bin.push_back((n >> i) & 1);
	}

	return bin;
}

void twos_complement(vector<int>& bin) {

	bool ok = false;
	for (int i = 31; i >= 0; --i) {
		if (ok) {
			bin[i] = 1 - bin[i];
		}
		else if (bin[i] == 1 && !ok) {
			ok = true;
		}
	}
}


string toHex(int num) {

	vector<int> bin = num_to_binary(abs(num));

	if (num < 0) {
		twos_complement(bin);
	}

	string s;
	for (int i = 0; i <= 31; i += 4) {

		int res = 0;
		for (int j = 0, k = i; j < 4; ++j, ++k) {
			res = res + pow(2, 4 - j - 1) * bin[k];
		}

		if (res < 10) {
			s += to_string(res);
		}
		else {
			s.push_back(hex_list[res]);
		}
	}

	string ans;
	bool ok = false;
	for (int i = 0; i < s.size(); ++i) {
		if (ok) {
			ans.push_back(s[i]);
		}
		else if (s[i] != '0' && !ok) {
			ok = true;
			ans.push_back(s[i]);
		}
	}

	return ans.size() > 0 ? ans : "0";
}

int main() {

	for (int i = -31; i <= 31; ++i) {
		cout << i << " " << toHex(i) << endl;
	}
}