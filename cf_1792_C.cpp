/*
https://codeforces.com/contest/1792/problem/C
*/
#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;

	vector<int> vec(n+2);

	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		vec[x]=i;
	}

	int l=(n+1)/2, r=(n+2)/2;

	while(l>0 && (l==r || (vec[l]<vec[l+1] && vec[r-1]<vec[r]))){
		--l,++r;
	}

	// cout<<l<<" "<<r<<endl;
	cout<<(n-r+l+1)/2<<endl;
}

int main(){
	int t;
	cin>>t;

	while(t--) {
	    solve();
	}
}