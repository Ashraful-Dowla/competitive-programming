/*
https://codeforces.com/contest/1790/problem/B
*/
#include<bits/stdc++.h>
using namespace std;


void solve(){
	int n,s,r;
	cin>>n>>s>>r;

	vector<int> vec;
	int mx=s-r;

	for(int i=0;i<n-1;++i){
		vec.push_back(1);
		r--;	
	}

	int idx=0;
	while(r>0){
		if(vec[idx]+1<=mx) vec[idx]++;
		r--,idx++;
		if(idx==vec.size()) idx=0;
	}

	vec.push_back(mx);
	sort(vec.begin(),vec.end());

	for(auto val:vec){
		cout<<val<<" ";
	}
	cout<<endl;
}

int main(){
	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}