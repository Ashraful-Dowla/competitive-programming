/*
https://codeforces.com/problemset/problem/1373/D
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<ll>vec;
		ll even=0;
		for(int i=0;i<n;++i){
			ll x;
			cin>>x;
			vec.push_back(x);
			if(i%2==0) even+=vec[i];
		}

		ll c=0,m=0;
		for(int i=0;i<n-1;i+=2){
			c+=(vec[i+1]-vec[i]);
			c = max(0LL,c);
			m = max(c,m);
		}

		c=0;
		for(int i=1;i<n-1;i+=2){
			c+=(vec[i]-vec[i+1]);
			c = max(0LL,c);
			m = max(c,m);
		}
		cout<<even+m<<endl;
	}
}