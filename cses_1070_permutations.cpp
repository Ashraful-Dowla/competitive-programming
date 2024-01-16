/*
https://cses.fi/problemset/task/1070/
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	if (n == 1) {
		cout << 1 << endl;
	}
	else if (n <= 3) {
		cout << "NO SOLUTION" << endl;
	}
	else if (n % 2 == 0) {

		vector<int> v(n);

		int c = 1;
		for (int i = 1; i < n; i += 2) {
			v[i] = c++;
		}

		for (int i = 0; i < n; i += 2) {
			v[i] = c++;
		}

		for (int i = 0; i < n; ++i) {
			cout << v[i] << " ";
		}
		cout << endl;
	}
	else {
		vector<int> v(n);

		int c = 1;

		for (int i = 0; i < n; i += 2) {
			v[i] = c++;
		}

		for (int i = 1; i < n; i += 2) {
			v[i] = c++;
		}

		for (int i = 0; i < n; ++i) {
			cout << v[i] << " ";
		}
		cout << endl;
	}
}