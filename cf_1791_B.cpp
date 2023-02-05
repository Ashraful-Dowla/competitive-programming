/*
https://codeforces.com/contest/1791/problem/B
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

const int MOD=1e9+7;

void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;

	int x=0,y=0;
	for(int i=0;i<n;++i){
		if(s[i]=='L') x--;
		else if(s[i]=='R') x++;
		else if(s[i]=='U') y++;
		else y--;

		if(x==1 && y==1){
			cout<<"YES"<<endl;
			return ;
		}
	}

	cout<<"NO"<<endl;
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