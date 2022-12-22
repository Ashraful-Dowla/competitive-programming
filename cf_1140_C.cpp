/*
https://codeforces.com/contest/1140/problem/C
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	int n,k;
	cin>>n>>k;
	vector<pair<ll,ll>>vec;

	for(int i=0;i<n;++i){
		ll t,b;
		cin>>t>>b;
		vec.push_back({b,t});
	}

	sort(vec.begin(), vec.end());

	set<pair<ll,int>>s;
	ll sum=0,ans=0;
	for(int i=vec.size()-1;i>=0;--i){
		ll b=vec[i].first;
		ll t=vec[i].second;
		s.insert({t,i});
		sum+=t;
		while(s.size()>k){
			auto val = s.begin();
			sum-=(val->first);
			s.erase(val);
		}
		ans = max(ans, sum*b);
	}
	cout<<ans<<endl;
}