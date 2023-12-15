#include <bits/stdc++.h>
using namespace std;


void printBinary(int n) {

	for (int i = 6; i >= 0; --i) {
		cout << ((n >> i) & 1);
	}
	cout << endl;
}

int main() {

	vector<int> A = {1, 4, 6};
	vector<int> B = {2, 4, 5};

	int a = 0;

	for (int x : A) {
		a |= (1 << x);
	}

	int b = 0;
	for (int x : B) {
		b |= (1 << x);
	}

	int c = a ^ b; // difference

	int mask = c & -c; // rightmost bit where differ starts

	//A - B
	for (int i = 0; i <= 10; ++i) {
		int v = (a & mask);
		if ((v & (1 << i))) {
			cout << i << " ";
		}
	}

	cout << endl;

	// B-A
	for (int i = 0; i <= 10; ++i) {
		int v = (b & mask);
		if ((v & (1 << i))) {
			cout << i << " ";
		}
	}

	cout << endl;

}