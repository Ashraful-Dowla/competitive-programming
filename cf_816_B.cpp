/*
https://codeforces.com/contest/816/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

const int N=2e5+10;
int pf[N],res[N];

int main(){
	int n,k,q;
	cin>>n>>k>>q;

	for(int i=0;i<n;++i){
		int x,y;
		cin>>x>>y;
		pf[x]++;
		pf[y+1]--;
	}

	vector<int>vec;
	for(int i=1;i<N;++i){
		pf[i]+=pf[i-1];
		res[i]+=res[i-1];
		if(pf[i]>=k) res[i]++;
	}
	while(q--) {
	   int x,y;
	   cin>>x>>y;
	   cout<<res[y]-res[x-1]<<endl;
	}
}