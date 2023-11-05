/*
https://www.hackerearth.com/problem/algorithm/christmas-tree-of-height-n/
*/
#include <bits/stdc++.h>
using namespace std;
long long arr[41][41];

void generate_pascale_triangle() {
	arr[1][1] = 1;
	for (int i = 2; i <= 40; i++) {
		for (int j = 1; j <= i; j++) {
			arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
		}
	}
}

void prnt(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}
int main() {
	int t;
	cin >> t;
	generate_pascale_triangle();
	while (t--) {
		int n;
		cin >> n;
		prnt(n);
	}
}