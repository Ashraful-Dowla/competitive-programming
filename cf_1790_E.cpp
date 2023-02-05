/*
https://codeforces.com/contest/1790/problem/E
*/
#include<bits/stdc++.h>
using namespace std;

void solve(){
	int x;
	cin>>x;

	if(x&1){
		cout<<-1<<endl;
		return ;
	}

	int a = 3*(x/2);
	int b = x/2;

	if((a^b)==x) cout<<a<<" "<<b<<endl;
	else cout<<-1<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}