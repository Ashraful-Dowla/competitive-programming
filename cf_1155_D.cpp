/*
https://codeforces.com/contest/1155/problem/D
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll n,x;
	cin>>n>>x;

	ll cur1=0,cur2=0,cur=0,res=0;
	for(int i=0;i<n;++i){
		ll a;
		cin>>a;
		cur1 = max(cur1+a,0LL);
		cur2 = max(cur2+x*a,cur1);
		cur = max(cur+a,cur2);
		res = max(res,cur);
	}
	cout<<res<<endl;
}