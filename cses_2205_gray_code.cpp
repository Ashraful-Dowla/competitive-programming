/*
https://cses.fi/problemset/task/2205/
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < (1 << n); ++i) {
		int v = i ^ (i >> 1);

		for (int i = n - 1; i >= 0; --i) {
			if ((v & (1 << i))) cout << 1;
			else cout << 0 ;
		}
		cout << endl;
	}

}