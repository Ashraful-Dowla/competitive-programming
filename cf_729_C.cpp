/*
https://codeforces.com/contest/729/problem/C
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pr;
typedef long long ll;

const int N=2e5+10;
int n,k,s,t;

int gas_stations[N];
vector<pr>cars;

bool possible(ll x){
	ll y,tz=0;
	for(int i=1;i<=k;++i){
		y = gas_stations[i] - gas_stations[i-1];
		if(y>x) return false;
		tz += 2*y - min(y,x-y);
	}

	return tz<=t;
}

int main(){
	cin>>n>>k>>s>>t;

	for(int i=0;i<n;++i){
		int c,v;
		cin>>c>>v;
		cars.push_back({c,v});
	}
	
	for(int i=1;i<=k;++i){
		cin>>gas_stations[i];
	}

	gas_stations[++k]=s;
	sort(gas_stations,gas_stations+k);

	ll lo=0,hi=INT_MAX,mid,ans=INT_MAX;

	while(hi>lo) {
		mid = (hi+lo)/2;
		if(possible(mid)) hi=mid;
		else lo=mid+1;
	}

	for(auto car: cars){
		int c,v;
		tie(c,v) = car;
		if(v>=lo) ans = min(ans,c*1LL);
	}
	
	if(ans==INT_MAX) cout<<-1<<endl;
	else cout<<ans<<endl;
}