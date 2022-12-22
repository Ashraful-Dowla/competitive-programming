/*
https://codeforces.com/contest/1182/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll _pow(ll n){
	ll ans=1;
	for(int i=0;i<n;++i){
		ans*=2;
	}
	return ans;
}

int main(){
	ll n;
	cin>>n;
	if(n%2==1) cout<<0<<endl;
	else cout<<_pow(n/2)<<endl;
}