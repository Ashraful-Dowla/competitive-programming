/*
https://codeforces.com/contest/1736/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll lcm(ll a,ll b){
	ll gcd = __gcd(a,b);
	return (a*b)/gcd;
}

int main(){
	int t;
	cin>>t;

	while(t--) {
	    int n;
	    cin>>n;
	    vector<ll>a(n+2,1);

	    for(int i=1;i<=n;++i){
	    	cin>>a[i];
	    }

	    vector<ll>b(n+2);
	    for(int i=1;i<=n+1;++i){
	    	b[i]=lcm(a[i],a[i-1]);
	    }

	    bool ok=true;
	    for(int i=1;i<=n;++i){
	    	ll val = __gcd(b[i],b[i+1]);
	    	if(val==a[i]) continue;

	    	ok=false;
	    	break;
	    }

	    cout<<(ok? "YES": "NO")<<endl;

	}
}