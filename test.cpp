#include <bits/stdc++.h>
using namespace std;

int main() {


	while (true) {

		cout << "press 1: add" << endl;
		cout << "press 2: subract" << endl;
		cout << "press 3: multiply" << endl;
		cout << "press 4: divisble" << endl;
		cout << "press 0: exit" << endl;

		int t;
		cin >> t;

		if (t > 4) {
			cout << "Please enter a valid type" << endl;
			continue;
		}

		if (t == 0) break;
		else {
			cout << "Enter two number" << endl;
			int a, b;
			cin >> a >> b;

			if (t == 1) {
				cout << a + b << endl;
			}
			else if (t == 2) {
				cout << a - b << endl;
			}
			else if (t == 3) {
				cout << a*b << endl;
			}
			else {
				if (b == 0) {
					cout << "Undefined" << endl;
				}
				else {
					cout << a / b << endl;
				}
			}
		}
	}
}