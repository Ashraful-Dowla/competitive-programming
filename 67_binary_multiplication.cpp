#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll M = 1e18+7;


ll binaryMultiply(ll a,ll b){
	ll ans=0;
	while(b>0){
		if(b&1) ans=(ans+a)%M;
		a=(a+a)%M;
		b>>=1;
	}
	return ans;
}

ll binaryExp(ll a,ll b){
	ll ans = 1;
	while(b){
		if(b&1) ans=binaryMultiply(ans,a); // m is larage
		a=binaryMultiply(a,a);
		b>>=1;
	}
	return ans;
}


//log^2(N)
int main(){
	ll a=2,b=13;
	cout<<binaryExp(a,b)<<endl;
}