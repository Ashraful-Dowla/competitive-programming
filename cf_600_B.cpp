/*
https://codeforces.com/problemset/problem/600/B
*/
#include <bits/stdc++.h>
using namespace std;

const int N=2e5+10;

typedef long long ll;
vector<ll>vec,vec2,ans;

int main(){
	int n,m;
	cin>>n>>m;

	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		vec.push_back(x);
	}

	for(int i=0;i<m;++i){
		int x;
		cin>>x;
		vec2.push_back(x);
	}

	sort(vec.begin(),vec.end());

	for(ll &val: vec2){
		auto it = upper_bound(vec.begin(),vec.end(),val);
		ans.push_back(it-vec.begin());
	}
	
	for(ll &val: ans){
		cout<<val<<" ";
	}
	cout<<endl;
}