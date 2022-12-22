#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int M = 1e9+7;

// log(b)
ll binaryExp(ll a,ll b){
	ll ans = 1;
	while(b){
		if(b&1) ans =(ans*a)%M;
		a=(a*a)%M;
		b>>=1;
	}
	return ans;
}

int main(){
	ll a=222,b=132;
	cout<<binaryExp(a,b)<<endl;
}