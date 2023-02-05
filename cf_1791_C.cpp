/*
https://codeforces.com/contest/1791/problem/C
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

	int l=0,r=n-1, len=n;

	while(l<r){
		if(s[l]=='0' && s[r]=='1'){
			l++,r--;
			len-=2;
		}
		else if(s[l]=='1' && s[r]=='0'){
			l++,r--;
			len-=2;
		} 
		else break;
	}

	cout<<len<<endl;
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