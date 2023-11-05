/*
https://www.hackerearth.com/problem/algorithm/monk-and-his-love-for-primes/
*/

#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int main() {
	string s;
	cin >> s;
	int sum = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			sum -= (s[i] + 32);
		}
		else if (s[i] >= 'a' && s[i] <= 'z') {
			sum += (s[i] - 32);
		}
	}
	sum = abs(sum);
	cout << is_prime(sum) << endl;
}