/*
https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/monk-and-the-magical-candy-bags/?fbclid=IwAR2kDiVkEaxu9dkCTCUhzXLuIccNn0Gz3dSfkaSUjlDE6Nb9UHMzt8HNDo4
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		multiset<long long> bags;
		for (int i = 0; i < n; i++) {
			long long candy;
			cin >> candy;
			bags.insert(candy);
		}

		long long total = 0;

		for (int i = 0; i < k; i++) {
			auto last_it = (--bags.end());
			total += (*last_it);
			bags.erase(last_it);
			bags.insert((*last_it) / 2);
		}

		cout << total << endl;
	}
}