#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll n,b;
	cin>>n>>b;
	ll ans=1e18;

	for(ll i=2;i<=b;++i){

		if (i*i> b) i = b;
		int cnt=0;
		while(b%i==0) {
		    cnt++;
		    b/=i;
		}

		if(cnt==0) continue;
		ll temp=0,mul=1;

		while(mul<=n/i){
			mul*=i;
			temp+=n/mul;
		}

		ans=min(ans,temp/cnt);
	}

	cout<<ans<<endl;
}