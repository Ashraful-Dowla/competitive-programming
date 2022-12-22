/*
https://codeforces.com/problemset/problem/1200/C
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll n,m;
	int q;
	cin>>n>>m>>q;

	while(q--) {
	    ll s_x,s_y,e_x,e_y;
	    cin>>s_x>>s_y>>e_x>>e_y;

	    ll gcd = __gcd(n,m);
	    ll blk[3];
	    blk[1]=n/gcd;
	    blk[2]=m/gcd;

	    if((s_y-1)/blk[s_x] == (e_y-1)/blk[e_x]) cout<<"YES"<<endl;
	    else cout<<"NO"<<endl;
	}
}