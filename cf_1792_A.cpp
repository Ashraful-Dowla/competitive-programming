/*
https://codeforces.com/contest/1792/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

void solve(){	
	int n;
	cin>>n;

	vector<int> vec;
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		vec.push_back(x);
	}

	sort(vec.begin(),vec.end());

	int ans=0;
	for(int i=0;i+1<n;i+=2){
		ans+=min(2,(vec[i]+vec[i+1]+1)/2);
	}

	cout<<min(n,ans+n%2)<<endl;
}

int main(){
	int t;
	cin>>t;

	while(t--) {
	    solve();
	}
}