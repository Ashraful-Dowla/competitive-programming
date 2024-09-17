/*
https://atcoder.jp/contests/abc369/tasks/abc369_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int a, b;
	cin >> a >> b;

	multiset<int> ms;
	ms.insert(a);
	ms.insert(b);


	int ans = 0;
	for (int x = -200; x <= 200; ++x) {
		ms.insert(x);

		auto t = ms.begin();
		auto A = t;
		t++;
		auto B = t;
		t++;
		auto C = t;

		if (*B - *A == *C - *B) {
			ans++;
		}

		ms.erase(ms.find(x));
	}

	cout << ans << endl;
}