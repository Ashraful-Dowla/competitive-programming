/*
https://codeforces.com/contest/1091/problem/C
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;	

int main(){
	ll n;
	cin>>n;

	set<ll>s;
	for(ll i=1;i*i<=n;++i){
		if(n%i==0){
			ll res = n*(i-1)/2 +i;
			s.insert(res);

			ll ii = n/i;
			res = n*(ii-1)/2 +ii;
			s.insert(res);
		}
	}


	for(auto val:s){
		cout<<val<<" ";
	}
	cout<<endl;
}