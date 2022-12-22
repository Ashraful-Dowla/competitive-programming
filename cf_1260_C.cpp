/*
https://codeforces.com/problemset/problem/1260/C
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	int t;
	cin>>t;

	while(t--) {
	    ll r,b,k;
	    cin>>r>>b>>k;

	    ll gcd = __gcd(r,b);

	    r/=gcd,b/=gcd;

	    if(r>b) swap(r,b);

	    if((k-1)*r+1<b) cout<<"REBEL"<<endl;
	    else cout<<"OBEY"<<endl;
	}
}