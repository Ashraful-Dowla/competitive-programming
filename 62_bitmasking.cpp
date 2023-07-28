#include <bits/stdc++.h>
using namespace std;

void printBinary(int num) {
	for (int i = 32; i >= 0; --i) {
		cout << ((num >> i) & 1);
	}
	cout << endl;
}

int main() {
	int n;
	cin >> n;
	vector<int>masks(n, 0);

	for (int i = 0; i < n; ++i) {
		int n_workers;
		cin >> n_workers;
		int mask = 0;
		for (int j = 0; j < n_workers; ++j) {
			int d;
			cin >> d;
			mask = (mask | (1 << d));
		}
		masks[i] = mask;
	}

	// for(int i=0;i<n;++i){
	// 	cout<<masks[i]<<endl;
	// 	printBinary(masks[i]);
	// }

	int max_days = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int intersection = (masks[i] & masks[j]);
			int common_days = __builtin_popcount(intersection);

			max_days = max(max_days, common_days);

			// cout<<i<<" "<<j<<" "<<common_days<<endl;
		}
	}

	cout << max_days << endl;
}