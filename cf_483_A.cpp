/*
https://codeforces.com/contest/483/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll l,r;
	cin>>l>>r;

	bool chk=false;
	for(ll i=l;i<=r;++i){
		for(ll j=i+1;j<=r;++j){
			if(__gcd(i,j)!=1) continue;
			for(ll k=j+1;k<=r;++k){
				if(__gcd(j,k)!=1 || __gcd(i,k)==1) continue;
				cout<<i<<" "<<j<<" "<<k<<"\n";
				chk=true;
				break;
			}
			if(chk) break;
		}
		if(chk) break;
	}
	if(!chk) cout<<-1<<"\n";
}