#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int a, b;
	cin >> a >> b;

	ll ans = 1;
	for (int i = 0; i < b; ++i) {
		ans *= a;
	}

	cout << ans << endl;
}