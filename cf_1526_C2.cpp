/*
https://codeforces.com/contest/1526/problem/C2
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	int n;
	cin>>n;
	int cnt=0;
	ll sum=0;
	multiset<ll>ms;
	for(int i=0;i<n;++i){
		ll x;
		cin>>x;
		sum+=x;
		cnt++;
		ms.insert(-x);

		while(sum<0) {
		    auto it = --ms.end();
		    sum+=*it;
		    ms.erase(it);
		}
	}
	cout<<ms.size()<<endl;
}