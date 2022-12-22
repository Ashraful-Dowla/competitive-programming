#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a,ll b){
	return b==0 ? a : gcd(b,a%b);
}

int main(){
	int t;
	cin>>t;

	while(t--) {
	    ll n,m;
	    cin>>n>>m;

	    ll tt=1;

	    while(tt/gcd(tt,n)<=m){
	    	tt*=10;
	    }

	    tt/=10;
	    ll d = tt/gcd(tt,n);
	    cout<<n*(m/d)*d<<endl;
	}
}