
#include <bits/stdc++.h>
using namespace std;

// time complexity -> O(2^N)
void hanoi(int n, int st, int nd) {

	if (n == 1) {
		cout << st << "->" << nd << endl;
		return;
	}

	int other = 6 - (st + nd);
	hanoi(n - 1, st, other);
	cout << st << "->" << nd << endl;
	hanoi(n - 1, other, nd);
}

int main() {

	int n = 3, st = 1, nd = 3;
	hanoi(n, st, nd);
}