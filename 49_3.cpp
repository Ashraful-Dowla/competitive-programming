/*
https://www.hackerearth.com/problem/algorithm/help-joe-ii/
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll binary_search(vector<ll> &vec, ll x_mod, ll m){
	int start = 0;
	int end = vec.size()-1;

	ll ans=vec[vec.size()-1];
	while(start<=end){
		int mid = (start+end)/2;
		if(vec[mid]+x_mod<=m-1){
			ans=vec[mid];
			start = mid+1;
		}
		else end = mid-1;
	}

	return (ans+x_mod)%m;
}

int main(){
	int n;
	ll m;
	cin>>n>>m;
	vector<ll>vec;
	for(int i=0;i<n;i++){
		ll x;
		cin>>x;
		vec.push_back(x%m);
	}
	int q;
	cin>>q;
	sort(vec.begin(),vec.end());
	while(q--){
		ll x,x_mod;
		cin>>x;
		x_mod = x%m;
		cout<<binary_search(vec,x_mod,m)<<endl;
	}
}