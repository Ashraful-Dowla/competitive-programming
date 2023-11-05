/*
https://atcoder.jp/contests/abc327/tasks/abc327_c
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int arr[9][9];

	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cin >> arr[i][j];
		}
	}

	//row
	for (int i = 0; i < 9; ++i) {

		set<int>s;
		for (int j = 0; j < 9; ++j) {
			s.insert(arr[i][j]);
		}

		if (s.size() != 9) {
			cout << "No" << endl;
			return 0;
		}
	}

	//col
	for (int i = 0; i < 9; ++i) {

		set<int>s;
		for (int j = 0; j < 9; ++j) {
			s.insert(arr[j][i]);
		}

		if (s.size() != 9) {
			cout << "No" << endl;
			return 0;
		}
	}

	// box
	for (int i = 0; i < 9; i += 3) {

		set<int> s;
		for (int r = i; r < i + 3; ++r) {
			for (int c = 0; c < 3; c++) {
				s.insert(arr[r][c]);
			}
		}

		if (s.size() != 9) {
			cout << "No" << endl;
			return 0;
		}

		s.clear();

		for (int r = i; r < i + 3; ++r) {
			for (int c = 3; c < 6; c++) {
				s.insert(arr[r][c]);
			}
		}

		if (s.size() != 9) {
			cout << "No" << endl;
			return 0;
		}

		s.clear();

		for (int r = i; r < i + 3; ++r) {
			for (int c = 6; c < 9; c++) {
				s.insert(arr[r][c]);
			}
		}

		if (s.size() != 9) {
			cout << "No" << endl;
			return 0;
		}

	}


	cout << "Yes" << endl;
}