/*
https://codeforces.com/contest/1203/problem/C
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll divisors(ll n){
	ll cnt=0;
	for(ll i=1;i*i<=n;++i){
		if(n%i==0){
			cnt++;
			if(i!=(n/i)) cnt++;
		}
	}

	return cnt;
}

int main(){
	int n;
	// cin>>n;
	scanf("%d",&n);

	ll gcd=0;
	for(int i=0;i<n;++i){
		ll x;
		cin>>x;
		gcd= __gcd(gcd,x);
	}

	printf("%d\n",divisors(gcd));
}