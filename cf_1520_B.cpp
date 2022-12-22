/*
https://codeforces.com/problemset/problem/1520/B
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll>vec;

ll _pow(int a,int b){
	ll ans=1;
	for(int i=0;i<b;++i){
		ans*=a;
	}
	return ans;
}

void precompute(){
	ll s=0;
	for(int i=0;i<10;++i){
		s+=1LL*_pow(10,i);
		ll n = _pow(10,i+1);
		for(ll j=s;j<n;j+=s){
			vec.push_back(j);
		}		
	}
}


int main(){
	precompute();
	int t;
	cin>>t;
	while(t--) {
	   ll n;
	   cin>>n;
	   auto it = upper_bound(vec.begin(),vec.end(),n);
	   cout<<(it-vec.begin())<<endl;
	}
}