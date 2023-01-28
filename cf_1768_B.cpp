/*
https://codeforces.com/contest/1768/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,k;
	cin>>n>>k;

	vector<int> vec;

	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		vec.push_back(x);
	}

	int cnt=1;
	for(int i=0;i<n;++i){
		if(vec[i]==cnt) cnt++;
	}

	cout<<(n-cnt+k)/k<<endl;
}

int main(){
	int t;
	cin>>t;

	while(t--) {
	    solve();
	}
}