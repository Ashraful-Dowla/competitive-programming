#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int>divisors[N];
int sum[N];

int main() {
	//O(nlog(n))
	for (int i = 2; i < N; ++i) {
		for (int j = i; j < N; j += i) {
			divisors[j].push_back(i);
			sum[j] += i;
		}
	}

	for (int i = 50; i < 100; ++i) {
		for (int v : divisors[i]) {
			cout << v << " ";
		}
		cout << endl;
	}
}