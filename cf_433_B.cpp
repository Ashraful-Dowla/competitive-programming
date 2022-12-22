/*
https://codeforces.com/problemset/problem/433/B
*/
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
long long pf[N],sorted_pf[N],arr[N];

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>arr[i];
		pf[i] = arr[i]+pf[i-1];
	}
	sort(arr+1,arr+n+1);
	for(int i=1;i<=n;++i){
		sorted_pf[i] = arr[i]+sorted_pf[i-1];
	}
	int m;
	cin>>m;
	while(m--) {
	   int t,l,r;
	   cin>>t>>l>>r;
	   if(t==1) cout<<(pf[r]-pf[l-1])<<endl;
	   else cout<<(sorted_pf[r]-sorted_pf[l-1])<<endl;
	}
}