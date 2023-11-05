/*
https://leetcode.com/problems/k-th-symbol-in-grammar/
*/
#include<bits/stdc++.h>
using namespace std;

int s;

void fnd(int k) {
	if (k == 1) s = 0;
	else {
		if (s == 1) s = k % 2 != 0 ? 1 : 0;
		else s = k % 2 != 0 ? 0 : 1;
	}
	return ;
}


void generate(int n, int k) {
	if (n == 0) return ;
	if ((k + 1) % 2 == 0) generate(n - 1, (k + 1) / 2);
	else generate(n - 1, k / 2);
	fnd(k);
	// cout<<k<<endl;
}

int main() {
	int n, k;
	cin >> n >> k;
	generate(n, k);
	cout << s << endl;
}