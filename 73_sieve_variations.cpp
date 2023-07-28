#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
vector<bool>isPrime(N, true);
vector<int>lp(N, 0), hp(N, 0);

int main() {
	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i < N; ++i) {
		if (isPrime[i]) {
			hp[i] = lp[i] = i;
			for (int j = 2 * i; j < N; j += i) {
				isPrime[j] = false;
				hp[j] = i;
				if (lp[j] == 0) lp[j] = i;
			}
		}
	}

	// for(int i=2;i<100;++i){
	// 	cout<<i<<"->"<<lp[i]<<" "<<hp[i]<<endl;
	// }

	int num;
	cin >> num;
	vector<int>prime_factors;

	//log(n)
	while (num > 1) {
		int prime_factor = hp[num];
		while (num % prime_factor == 0) {
			num /= prime_factor;
			prime_factors.push_back(prime_factor);
		}
	}

	for (int factor : prime_factors) {
		cout << factor << " ";
	}
	cout << endl;
}