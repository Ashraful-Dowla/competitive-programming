#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int M = 1e9+7;

// log(b)
ll binaryExp(ll a,ll b,ll m){
	ll ans = 1;
	while(b){
		if(b&1) ans =(ans*a)%m;
		a=(a*a)%m;
		b>>=1;
	}
	return ans;
}

int main(){
	// 50^64^32
	cout<<binaryExp(50,binaryExp(64,32,M-1),M)<<endl;
}