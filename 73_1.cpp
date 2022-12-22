/*
https://codeforces.com/contest/230/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e6+10;
vector<bool>isPrime(N,true);
map<ll,bool>mp;

void primeList(){
	for(int i=2;i<N;++i){
		if(isPrime[i]){
			mp[i*1LL*i]=true;
			for(int j=2*i;j<N;j+=i){
				isPrime[j]=false;
			}
		}
	}
}

int main(){
	int n;
	cin>>n;
	primeList();
	while(n--){
		ll t;
		cin>>t;
		if(mp[t]) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}	