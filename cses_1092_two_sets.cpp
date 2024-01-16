#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	int sum = n * (n + 1);
	sum /= 2;

	if (sum & 1) {
		cout << "NO" << endl;
	}
	else {

		cout << "YES" << endl;

		vector<int>a, b;

		bool chk = true;
		while (n > 0) {

			if (chk) {
				a.push_back(n);
				b.push_back(n - 1);
			}
			else {
				b.push_back(n);
				a.push_back(n - 1);
			}
			chk = 1 - chk;
			n -= 2;
		}

		if (a.back() == 0) {
			a.pop_back();
		}
		else if (b.back() == 0) {
			b.pop_back();
		}

		cout << a.size() << endl;
		for (int x : a) {
			cout << x << " ";
		}
		cout << endl;

		cout << b.size() << endl;
		for (int x : b) {
			cout << x << " ";
		}
		cout << endl;
	}

}