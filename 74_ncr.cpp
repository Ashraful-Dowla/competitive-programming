#include <bits/stdc++.h>
using namespace std;

//calculate nCr = n!/(n-r)!*r!

const int M=1e9+7;

int binaryExp(int a,int b, int m){
	int ans=1;	
	while(b) {
	    if(b&1) ans = (ans*1LL*a)%m;
	    a=(a*1LL*a)%m;
	    b>>=1;
	}

	return ans;
}

const int N=1e6+10;
int fact[N];

int main(){
	fact[0]=1;
	for(int i=1;i<N;++i){
		fact[i] = (fact[i-1]*1LL*i)%M;
	}
	int q;
	cin>>q;
	while(q--){
		int n,r;
		cin>>n>>r;
		int ans = fact[n];
		int den = (fact[n-r]*1LL*fact[r])%M;
		ans = (ans*1LL*binaryExp(den,M-2,M))%M;
		cout<<ans<<endl;
	}
}