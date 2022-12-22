/*
https://codeforces.com/contest/235/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll n;
	cin>>n;

	ll a=n,b=n-1,c=n-2;

	if(n==1||n==2) cout<<n<<endl;
	else if(n%2!=0) {
		ll ans = a*b*c;
		cout<<ans<<endl;
	}
	else {
		if(n%3==0) a-=1,b-=1,c-=1;
		else c-=1;

		ll ans = a*b*c;

		cout<<ans<<endl;
	}
}