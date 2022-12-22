/*
https://codeforces.com/problemset/problem/1703/F
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pr;

const int N=2e5+10;
ll arr[N];

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;

		map<ll,ll>mp;
		vector<pr>vec;

		for(int i=1;i<=n;++i){
			cin>>arr[i];
		}

		for(int i=1;i<=n;++i){
			if(arr[i]<i) {
				vec.push_back({arr[i],i});
			}
		}

		sort(vec.begin(),vec.end());

		vector<ll>list;
		ll cnt=0;
		for(int i=0;i<vec.size();++i){
			cnt++;
			int val=vec[i].first;
			mp[val]=cnt;
			list.push_back(val);
		}

		ll sum=0,sz=vec.size();
		for(int i=0;i<sz;++i){
			pr it = vec[i];
			ll val = it.first;
			ll idx = it.second;
			auto fnd = lower_bound(list.begin(),list.end(),idx);
			if(fnd!=list.end()){
				ll nw;
				if(*fnd==idx) nw=idx;
				else nw = *(--fnd);
				sum+=(sz-mp[nw]);
			}
		}
		cout<<sum<<endl;
	}
}