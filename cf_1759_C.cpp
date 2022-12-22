/*
https://codeforces.com/contest/1759/problem/C
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--) {
	   long l,r,x,a,b;
	   cin>>l>>r>>x;
	   cin>>a>>b;

	   if(a>b) swap(a,b);
	   if(a==b) cout<<0<<endl;
	   else if(abs(a-b)>=x) cout<<1<<endl;
	   else if(a-x>=l || b+x<=r) cout<<2<<endl;
	   else if(a+x<=r && b-x>=l) cout<<3<<endl;
	   else cout<<-1<<endl;
	}
}