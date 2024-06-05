#include <bits/stdc++.h>
using namespace std;

void add(string &s) {

	int carry = 0;
	for (int i = s.size() - 1; i >= 0; --i) {
		if (i == s.size() - 1) {
			if (s[i] == '0') {
				s[i] = '1';
				return ;
			}
			else {
				s[i] = '0';
				carry = 1;
			}
		}
		else {
			if (s[i] == '1') {
				if (carry) {
					s[i] = '0';
				}
				else {
					s[i] = '1';
					carry = 1;
				}
			}
			else {
				if (carry) {
					s[i] = '1';
					carry = 0;
				}
				return ;
			}
		}
	}

	if (carry) {
		s = "1" + s;
	}
	return ;
}

bool check(string &s) {

	for (int i = 0; i < s.size() - 1; ++i) {
		if (s[i] == '1') return false;
	}

	return s[s.size() - 1] == '1';
}

void shift(string &s) {

	char prv = s[0];
	for (int i = 1; i < s.size(); ++i) {
		char curr = s[i];
		s[i] = prv;
		prv = curr;
	}

	s[0] = '0';
	return ;
}

int numSteps(string s) {

	int step = 0;
	while (!check(s)) {
		if (s[s.size() - 1] == '1') {
			add(s);
		}
		else {
			shift(s);
		}
		step++;
	}

	return step;
}

int main() {

	// string s = "1101";
	// string s = "10";
	// string s = "1";
	// string s = "111110";
	string s = "1111";
	cout << numSteps(s) << endl;
}