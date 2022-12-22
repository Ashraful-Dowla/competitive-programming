/*
https://codeforces.com/problemset/problem/1471/A
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	int t;
	cin>>t;

	while(t--) {
	    ll n,x;
	    cin>>n>>x;

	    ll s1=0,s2=0;
	 	for(int i=0;i<n;++i){
	 		ll v;
	 		cin>>v;
	 		s1+=ceil((double)v/(double)x);
	 		s2+=v;
	 	}

	 	s2=ceil((double)s2/(double)x);
	 	cout<<min(s1,s2)<<" "<<max(s1,s2)<<endl;  
	}
}