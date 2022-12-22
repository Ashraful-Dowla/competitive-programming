/*
https://codeforces.com/contest/862/problem/C
*/
#include <bits/stdc++.h>
using namespace std;

#define pys cout<<"YES"<<endl;
#define pno cout<<"NO"<<endl;

int main(){
	int n,x;
	cin>>n>>x;

	if(n==1) {
		pys;
		cout<<x<<endl;
	}
	else if(n==2){
		if(x==0){
			pno;
		}
		else {
			pys;
			cout<<0<<" "<<x<<endl;
		}
	}
	else {
		int ans=0;
		pys;
		for(int i=1;i<=n-3;++i){
			cout<<i<<" ";
			ans^=i;
		}
		int pw=1<<17;
		if(ans==x) cout<<pw<<" "<<(pw*2)<<" "<<(pw^(pw*2))<<endl;
		else cout<<0<<" "<<pw<<" "<<(pw^ans^x)<<endl;
	}
}